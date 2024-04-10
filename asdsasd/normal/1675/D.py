import sys
input = sys.stdin.readline

def main():
    n = int(input())
    P = list(map(int, input().split()))
    P = [p - 1 for p in P]
    edges = [[] for _ in range(n)]
    for i, p in enumerate(P):
        if i == p:
            root = i
        else:
            edges[p].append(i)
    route = [root]
    stack = [root]
    while stack:
        pos = stack.pop()
        for npos in edges[pos]:
            route.append(npos)
            stack.append(npos)
    m = 0
    path = []
    ind = [-1] * n
    for r in route[::-1]:
        if ind[r] == -1:
            path.append([r + 1])
            ind[r] = m
            m += 1
        else:
            path[ind[r]].append(r + 1)
        ind[P[r]] = ind[r]
    print(m)
    for row in path:
        print(len(row))
        print(*row[::-1])

    
for _ in range(int(input())):
    main()
    print()