from collections import*
n = input()
a = list(map(int,raw_input().split()))
c = Counter(a)
res = 0
cur = 0
for i in sorted(c.keys()):
  d = min(c[i], cur)
  cur -= d
  res += d
  cur += c[i]
print(res)