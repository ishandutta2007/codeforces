from heapq import *
n, c = map(int, raw_input().split())
a = list(map(int, raw_input().split()))
if c > n:
 print(sum(a))
 exit()
b = [0] * n
s = 0
h = []
for i in range(n):
 s = s + a[i] - a[i-c] if i + 1 > c else s + a[i]
 heappush(h, (a[i],i)) 
 if i + 1 < c:
  b[i] = s
 else:
  while h[0][1] <= i-c:
   heappop(h)
  v1 = b[i-1] + a[i]   
  v2 = b[i-c] + s - h[0][0]
  b[i] = min(v1, v2)
print(b[-1])