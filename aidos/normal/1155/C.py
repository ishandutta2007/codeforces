import math
n, m = map(int, input().split())
a = list(map(int, input().split()))

g = a[1] - a[0]
for i in range(1, n):
    d = a[i] - a[i-1]
    if d % g != 0:
        g = math.gcd(d, g)

ind = -1
b = list(map(int, input().split()))
for i in range(m):
    if g % b[i] == 0:
        ind = i+1
if ind == -1:
    print('NO')
else:
    print('YES')
    print(a[0], ind)