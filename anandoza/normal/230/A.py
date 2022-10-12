from operator import itemgetter

s, n = tuple(int(i) for i in raw_input().split())
dragons = []
for j in range(n):
  dragons.append(tuple(int(i) for i in raw_input().split()))
dragons.sort(key=itemgetter(0))

for dragon in dragons:
  x, y = dragon
  if s <= x:
    print "NO"
    break
  s += y
else:
  print "YES"