from operator import itemgetter

n = int(raw_input())

laptops = []
for j in range(n):
  laptops.append(tuple(int(i) for i in raw_input().split()))

def outdated(x, laptops):
  return [y for y in laptops if all(x[i] < y[i] for i in range(3))]

modern = [x for x in laptops if not outdated(x, laptops)]

print laptops.index(min(modern, key=itemgetter(3)))+1