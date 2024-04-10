import math
n, k = map(int, input().split())
d = 10 ** k

h = math.gcd(n, d)
l = n * d//h

print(l)