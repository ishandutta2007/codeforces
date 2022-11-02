n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
l = []
cur = 0
ans = []
for i in range(n):
    l.append(0)
    cur ^= a[i][0]
if cur > 0:
    print('TAK')
    for i in range(n):
        print(l[i] + 1, end = ' ')
else:
    for i in range(n):
        t = -1
        for j in range(m):
            if a[i][j] != a[i][0]:
                t = j
        if t != -1:
            l[i] = t
            cur = 1
            break
    if cur > 0:
        print('TAK')
        for i in range(n):
            print(l[i] + 1, end = ' ')
    else:
        print('NIE')