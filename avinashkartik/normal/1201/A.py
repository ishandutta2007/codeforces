n,m = map(int,input().split())
a = []
for i in range(n):
  a.append(list(input()))
c = list(map(int,input().split()))
sum = 0
for i in range(m):
  d = dict()
  for j in range(n):

    if a[j][i] in d:
      d[a[j][i]] += 1
    else:
      d[a[j][i]] = 1
  sum += max([i for i in d.values()])*c[i]
print(sum)