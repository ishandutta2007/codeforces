t = int(input())
for _ in range(t):
    s = input()
    t = input()
    p = input()
    x = []
    j = 0

    for i in range(len(t)):
        if j < len(s) and s[j] == t[i]:
            j += 1
        else:
            x.append(t[i])

    if j != len(s):
        print('NO')
        continue
    for z in p:
        if z in x:
            g = x.index(z)
            x.pop(g)
    if len(x) == 0:
        print('YES')
    else:
        print('NO')