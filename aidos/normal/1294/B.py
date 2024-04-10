t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    a = sorted(a)
    x = 0
    y = 0
    ans = []
    bad = False
    for c in a:
        while x < c[0]:
            x += 1
            ans.append('R')
        while y < c[1]:
            y += 1
            ans.append('U')
        if x>c[0] or y > c[1]:
            bad = True
    if bad:
        print('NO')
    else:
        print('YES')
        print(''.join(ans))