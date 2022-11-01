from fractions import gcd
a, b, n = map(int, raw_input().split())
k = 0
while n != 0:
    n = n - (gcd(n, a))
    if n != 0:
        n = n - (gcd(n, b))
    else:
        print(0)
        k = 1
if k == 0:
    print(1)