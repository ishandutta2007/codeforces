import sys
input = sys.stdin.readline
from collections import deque

def main():
    n = int(input())
    edges = [[] for _ in range(n)]
    in_ = [0] * n
    for i in range(n):
        k, *alst = map(int, input().split())
        for a in alst:
            edges[a - 1].append(i)
            in_[i] += 1
    queue = deque()
    used = [False] * n
    max_ = [0] * n
    for i, o in enumerate(in_):
        if o == 0:
            queue.append((i, 1))
            used[i] = True
    while queue:
        pos, d = queue.popleft()
        for npos in edges[pos]:
            in_[npos] -= 1
            if npos > pos:
                max_[npos] = max(max_[npos], d)
            else:
                max_[npos] = max(max_[npos], d + 1)
                
            if in_[npos] == 0:
                used[npos] = True
                if max_[npos] == d:
                    queue.appendleft((npos, d))
                else:
                    queue.append((npos, d + 1))
    if False in used:
        d = -1
    print(d)
    
for _ in range(int(input())):
    main()