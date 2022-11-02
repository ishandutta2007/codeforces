t = int(input())
for _ in range(t):
    s = list(input())
    n = len(s)
    for i in range(n):
        if s[i] != '?':
            continue
        x = 'a'
        if i > 0 and s[i-1] == x:
            x = 'b'
        if i + 1 < n and s[i+1] == x:
            x = 'b'

        if i > 0 and s[i-1] == x:
            x = 'c'
        if i + 1 < n and s[i+1] == x:
            x = 'c'
        s[i] = x
    bad = 0
    for i in range(1, n):
        if s[i] == s[i-1]:
            bad = 1
    if bad:
        print(-1)
    else:
        print(''.join(s))