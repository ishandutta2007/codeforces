import sys
def main():
    n = int(raw_input())
    edges = list(map(int, sys.stdin.read().split()))
    tree_edges = dict()
    for i in range(n):
        tree_edges[i + 1] = set()
    for i in range(0, len(edges) - 1, 2):
        tree_edges[edges[i]].add(edges[i + 1])
        tree_edges[edges[i + 1]].add(edges[i])
    init_distants = [-1] * (n + 1)
    queue = [1]
    init_distants[1] = 0
    while queue:
        next_queue = []
        for process in queue:
            for next_vertex in tree_edges[process]:
                if init_distants[next_vertex] == -1:
                    init_distants[next_vertex] = init_distants[process] + 1
                    next_queue.append(next_vertex)
        queue = next_queue
    head = init_distants.index(max(init_distants))
    distants_from_head = [-1] * (n + 1)
    queue = [head]
    distants_from_head[head] = 0
    while queue:
        next_queue = []
        for process in queue:
            for next_vertex in tree_edges[process]:
                if distants_from_head[next_vertex] == -1:
                    distants_from_head[next_vertex] = distants_from_head[process] + 1
                    next_queue.append(next_vertex)
        queue = next_queue

    tail = distants_from_head.index(max(distants_from_head))
    distants_from_tail = [-1] * (n + 1)
    queue = [tail]
    distants_from_tail[tail] = 0
    while queue:
        next_queue = []
        for process in queue:
            for next_vertex in tree_edges[process]:
                if distants_from_tail[next_vertex] == -1:
                    distants_from_tail[next_vertex] = distants_from_tail[process] + 1
                    next_queue.append(next_vertex)
        queue = next_queue
    path_len_sum = 0
    removal_history = list()
    process_queue = []
    for vertex, adj in tree_edges.items():
        if len(adj) == 1:
            process_queue.append(vertex)
    while process_queue:
        next_queue = []
        for leaf in process_queue:
            if leaf == head or leaf == tail:
                continue
            if distants_from_tail[leaf] > distants_from_head[leaf]:
                path_len_sum += distants_from_tail[leaf]
                new_leaves = []
                for w in tree_edges[leaf]:
                    tree_edges[w].remove(leaf)
                    if len(tree_edges[w]) == 1:
                        new_leaves.append(w)
                next_queue.extend(new_leaves)
                removal_history.append("{0} {1} {0}".format(leaf, tail))
            else:
                path_len_sum += distants_from_head[leaf]
                new_leaves = []
                for w in tree_edges[leaf]:
                    tree_edges[w].remove(leaf)
                    if len(tree_edges[w]) == 1:
                        new_leaves.append(w)
                next_queue.extend(new_leaves)
                removal_history.append("{0} {1} {0}".format(leaf, head))
        process_queue = next_queue
    process_queue = [tail]
    while process_queue:
        leaf = process_queue[0]
        if leaf == head:
            continue
        path_len_sum += distants_from_head[leaf]
        new_leaves = []
        for w in tree_edges[leaf]:
            tree_edges[w].remove(leaf)
            if len(tree_edges[w]) == 1:
                new_leaves.append(w)
        process_queue = new_leaves
        removal_history.append("{0} {1} {0}".format(leaf, head))
    print(str(path_len_sum))
    sys.stdout.write("\n".join(removal_history))
    sys.stdout.write("\n")
main()