n, m, k = list(map(int, input().split()))
l = []

s = [0 for i in range(n)]
f = [False for i in range(k + 1)]

for i in range(n):
    l.append(list(map(int, input().split())))

for j in range(m):
    b = [-1 for i in range(k + 1)]
    for i in range(n):
        if s[i] or not l[i][j]:
            continue
        if f[l[i][j]]:
            s[i] = j + 1
        if b[l[i][j]] == -1:
            b[l[i][j]] = i
        else:
            s[b[l[i][j]]] = j + 1
            s[i] = j + 1
            f[l[i][j]] = True

for i in s:
    print(i)