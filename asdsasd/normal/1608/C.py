import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = [0] * n
    A = [(a, i) for i, a in enumerate(A)]
    B = [(b, i) for i, b in enumerate(B)]
    A.sort(reverse = True)
    B.sort(reverse = True)
    edges = [[] for _ in range(2 * n)]
    for i in range(1, n):
        edges[i].append((i - 1))
        edges[n + i].append((n + i - 1))
    ia = {}
    ind = {}
    for j, (a, i) in enumerate(A):
        ia[i] = j
        ind[j] = i
    for j, (b, i) in enumerate(B, n):
        edges[j].append(ia[i])
        edges[ia[i]].append(j)
    used = [False] * (2 * n)
    stack = [0, n]
    used[0] = True
    used[n] = True
    while stack:
        pos = stack.pop()
        for npos in edges[pos]:
            if used[npos]:
                continue
            used[npos] = True
            stack.append(npos)
    
    for i in range(n):
        if used[i]:
            ans[ind[i]] = 1
    print(*ans, sep="")
            
    
for _ in range(int(input())):
    main()