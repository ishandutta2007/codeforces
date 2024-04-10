n, k = map(int, input().split())
s = input()
l, r = int(-1), int(n)

while r - l > 1:
    m = (l+r)//2
    c, p = 1, 0
    cond = True
    while p < n and c < k:
        i = p + m + 1
        while i >= p and (i >= n or s[i] == '1'):
            i = i - 1;
        if (i == p):
            break
        c = c + 1
        p = i
    cond = cond and (p == n-1)
    if cond:
        r = m
    else:
        l = m
print(int(r))