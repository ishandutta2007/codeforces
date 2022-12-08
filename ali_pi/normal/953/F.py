n, p, m = [int(x) for x in raw_input().split(" ")]
d = []
t = []
for _ in xrange(0, n):
  a, b = [int(x) for x in (raw_input().split(" "))]
  d.append(a)
  t.append(b)
d.append(m+1)
t.append(0)
answer = 0
prev = 1
balance = 0
prevNeg = False
for i in xrange(0, n+1):
  balance = balance - (d[i] - prev)*p
  if (prevNeg):
    answer += d[i] - prev
  elif (balance < 0):
    b = balance * (-1)
    answer = answer + (b + p - 1)/p
  balance = balance + t[i]
  prev = d[i]
  if (balance < 0): prevNeg = True
  else: prevNeg = False
print (answer)