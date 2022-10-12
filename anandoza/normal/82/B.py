from math import ceil

n = int(raw_input())
combos = set()
for i in range(n*(n-1)/2):
  combos.add(frozenset(int(i) for i in raw_input().split(" ")[1:]))

answer = set()
elements = frozenset().union(*combos)
for x in elements:
  answer.add(elements.intersection(*[c for c in combos if x in c]))

if n == 2:
  output = [x for x in elements]
  print 1, output[0]
  print len(output[1:]), " ".join(map(str, output[1:]))
else:
  for s in answer:
    print len(s), " ".join(map(str, s))