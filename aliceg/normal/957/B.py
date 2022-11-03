import sys
sys.setrecursionlimit(1000000)
def dfsn(x):
    global n, m, usedn, usedm, a
    usedn[x] = 1
    f = 1
    for i in range(m):
        if a[x][i] == '#':
            if usedm[i] == 2:
                return 0
            elif not usedm[i]:
                f = min(dfsm(i), f)
        else:
            if usedm[i] == 1:
                return 0
    return f
    
def dfsm(x):
    global n, m, usedn, usedm, a
    usedm[x] = 1
    f = 1
    for i in range(n):
        if a[i][x] == '#':
            if usedn[i] == 2:
                return 0
            elif not usedn[i]:
                f = min(dfsn(i), f)
        else:
            if usedn[i] == 1:
                return 0
    return f


n, m = map(int, input().split())
a = [input() for i in range(n)]
usedn = [0] * n
usedm = [0] * m
f = 1
for i in range(n):
    if not usedn[i]:
        if not dfsn(i):
            f = 0
        for j in range(n):
             if usedn[j] == 1:
                 usedn[j] = 2
        for j in range(m):
             if usedm[j] == 1:
                 usedm[j] = 2
for i in range(m):
    if not usedm[i]:
        if not dfsm(i):
            f = 0
        for j in range(m):
             if usedm[j] == 1:
                 usedm[j] = 2
        for j in range(n):
             if usedn[j] == 1:
                 usedn[j] = 2
if f:
    print('Yes')
else:
    print('No')