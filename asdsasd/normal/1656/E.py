import sys
input = sys.stdin.readline

def main():
    n = int(input())
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    bi = [0] * n
    stack = [0]
    bi[0] = -1
    while stack:
        pos = stack.pop()
        for npos in edges[pos]:
            if bi[npos] != 0:
                continue
            bi[npos] = -bi[pos]
            stack.append(npos)
    print(*(len(edges[i]) * bi[i] for i in range(n)))
    
for _ in range(int(input())):
    main()