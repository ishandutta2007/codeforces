import sys
input = sys.stdin.readline

def main():
    p = int(input())
    n = 1 << p
    edges = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append((v, i))
        edges[v].append((u, i))

    ind = 1
    A = [0] * n
    A[0] = n
    bi = [-1] * n
    bi[0] = 0
    E = [0] * (n - 1)
    stack = [0]
    while stack:
        pos = stack.pop()
        for npos, i in edges[pos]:
            if A[npos] != 0:
                continue
            bi[npos] = bi[pos] ^ 1
            if bi[pos] == 0:
                A[npos] = ind
                E[i] = ind + n
            else:
                A[npos] = ind + n
                E[i] = ind
            ind += 1
            stack.append(npos)
    print(1)
    print(*A)
    print(*E)

    
for _ in range(int(input())):
    main()