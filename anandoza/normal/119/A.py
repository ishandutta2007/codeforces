from fractions import gcd

a, b, n = tuple(int(i) for i in raw_input().split())

while True:
  if gcd(a, n) <= n:
    n -= gcd(a, n)
  else:
    print 1
    break
  if gcd(b, n) <= n:
    n -= gcd(b, n)
  else:
    print 0
    break