n = int(raw_input())

coins = []

while n > 1:
  k = min(x for x in xrange(2, n+1) if n % x == 0)
  coins.append(n)
  n = n / k

coins.append(1)

print " ".join(map(str, coins))