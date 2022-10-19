from collections import deque
import sys
input = sys.stdin.buffer.readline

def main():
    n, a, b, da, db = map(int, input().split())
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    if da * 2 >= db:
        print("Alice")
        return
    
    a -= 1
    b -= 1
    queue = deque()
    queue.append(a)
    queue.append(0)
    check = [False for _ in range(n)]
    check[a] = True
    ab = -1
    while queue:
        pos = queue.popleft()
        d = queue.popleft() + 1
        for n_pos in edges[pos]:
            if check[n_pos]:
                continue
            check[n_pos] = True
            if n_pos == b:
                ab = d
            queue.append(n_pos)
            queue.append(d)
    if ab <= da:
        print("Alice")
        return
    queue = deque()
    queue.append(pos)
    queue.append(0)
    check = [False for _ in range(n)]
    check[pos] = True
    while queue:
        pos = queue.popleft()
        d = queue.popleft() + 1
        for n_pos in edges[pos]:
            if check[n_pos]:
                continue
            check[n_pos] = True
            queue.append(n_pos)
            queue.append(d)
    d -= 1
    if d <= da * 2:
        print("Alice")
    else:
        print("Bob")
    
    
t = int(input())
for _ in range(t):
    main()