t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    c = 0
    s = 0
    ans = sum(a)
    cnt = 0
    cntb = 1
    for x in a:
        s += x
        ans = max(ans, s-c)
        if ans == s-c:
            cnt += cntb

        if c > s:
            cntb = 0
            c = s

        if c == s:
            cntb += 1

    if ans > sum(a) or cnt > 1:
        print('NO')
    else:
        print('YES')