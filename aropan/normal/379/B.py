n, = map(int, raw_input().split())
a = map(int, raw_input().split())
x, d = 0, 1
l, r = 'L', 'R'
ans = ''
while max(a) != 0:
    for j in xrange(2 * (n - 1)):
        if a[x]:
            ans += 'P'
            a[x] -= 1
        ans += r
        x += d
        if x % (n - 1) == 0:
            l, r = r, l
            d = -d
print ans