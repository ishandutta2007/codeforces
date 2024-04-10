t = int(input())
for _ in range(t):
    n = int(input())
    a, b, c = map(int, input().split())
    cnt = 0
    s = list(input())
    ans = ['?'] * n

    for i in range(n):
        x = s[i]
        if x == 'R' and b > 0:
            ans[i] = 'P'
            b -= 1
            cnt += 1

        if x == 'P' and c > 0:
            ans[i] = 'S'
            c -= 1
            cnt += 1

        if x == 'S' and a > 0:
            ans[i] = 'R'
            a -= 1
            cnt += 1

    for i in range(n):
        if ans[i] != '?':
            continue
        x = s[i]
        if x == 'R' and a > 0:
            ans[i] = 'R'
            a -= 1

        if x == 'P' and b > 0:
            ans[i] = 'P'
            b -= 1

        if x == 'S' and c > 0:
            ans[i] = 'S'
            c -= 1
    for i in range(n):
        if ans[i] != '?':
            continue
        if a > 0:
            ans[i] = 'R'
        if b > 0:
            ans[i] = 'P'
        if c > 0:
            ans[i] = 'S'

    if cnt >= (n+1)//2:
        print('YES')
        print(''.join(ans))
    else:
        print('NO')