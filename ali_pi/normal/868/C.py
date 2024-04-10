n, k = map(int,raw_input().split())
a = set()
yes = False
for i in range(n):
 a.add(raw_input())
for w in a:
 for w2 in a:
  x = list(map(int, w.split()))
  y = list(map(int, w2.split()))
  count = 0
  for i in range(k):
   if x[i] + y[i] != 2:
    count += 1
  if count == k:
   yes = True
if yes:
 print("YES")
else:
 print("NO")