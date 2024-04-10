import sys
input = sys.stdin.readline
from heapq import *

def main():
    n, q = map(int, input().split())
    edges = [[] for _ in range(n)]
    P = list(map(int, input().split()))
    for i, p in enumerate(P, 1):
        edges[p - 1].append(i)
    for i in range(n):
        edges[i].sort(reverse = True)
    query = [[] for _ in range(n)]
    ans = [-1] * q
    for i in range(q):
        u, k = map(int, input().split())
        query[u - 1].append((i, k))
    fin = [False] * n
    dic = {}
    ind = 0
    stack = [(0, 0), (0, 1)]
    while stack:
        pos, t = stack.pop()
        if t == 0:
            fin[pos] = True
        else:
            for i, k in query[pos]:
                if ind + k not in dic:
                    dic[ind + k] = []
                dic[ind + k].append((i, pos))
            ind += 1
            if ind in dic:
                for i, bpos in dic[ind]:
                    if not fin[bpos]:
                        ans[i] = pos + 1
            for npos in edges[pos]:
                stack.append((npos, 0))
                stack.append((npos, 1))
    print(*ans, sep="\n")
            
    
for _ in range(1):
    main()