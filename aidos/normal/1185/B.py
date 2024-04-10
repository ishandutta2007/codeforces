n = int(input())
for i in range(n):
    a = input()
    b = input()
    r = 0
    bad = False
    for j in range(len(a)):
        if r == len(b) or b[r] != a[j]:
            if j == 0:
                bad = True
                break
            while r < len(b) and b[r] == a[j-1]:
                r += 1
            if r == len(b) or b[r] != a[j]:
                bad = True
                break
            r += 1
        else:
            r += 1
    while r < len(b) and b[r] == a[-1]:
        r += 1
    if r != len(b) or bad:
        print('NO')
    else:
        print('YES')