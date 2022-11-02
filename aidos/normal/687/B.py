import math
n, k = map(int, input().split())
a = list(map(int, input().split()))
g = 1
for i in a:
    g = math.gcd(k, i * g//math.gcd(i, g))
if g == k:
    print('Yes')
else:
    print('No')