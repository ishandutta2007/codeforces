n, k = map(int, input().split())
a = input()
g = 1
l, r = a.index('G'), a.index('T')
if l > r:
    l, r = r, l
while l + k<= r:
    if a[l] == '#':
        g = 0
    l += k
if l == r and g:
    print('YES')
else:
    print('NO')