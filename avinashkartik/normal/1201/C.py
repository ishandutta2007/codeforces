n,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
mid = int(n/2)
up = mid + 1
while(k>0):
  if(up >= n):
    k -= n-mid
    a[mid] += 1
  else:
    if(a[up] == a[mid]):
      up += 1
    else:
      k -= (up - mid)
      a[mid] += 1
if(k == 0):
  print(a[mid])
else:
  print(a[mid] - 1)