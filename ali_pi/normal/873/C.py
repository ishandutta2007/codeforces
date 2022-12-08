n,m,k = map(int,raw_input().split())
arr = []
for i in range(n):
  arr.append(list(map(int,raw_input().split())))
ans = 0
ans2 = 0
for i in range(m):
  cnt = 0
  res = 0
  res2 = 0
  for j in range(n):
    if arr[j][i]==1:
      cnt += 1
      temp = 0
      for l in range(j,min(j+k,n)):
        temp += arr[l][i]
      if temp > res:
        res = temp
        res2 = cnt-1
  ans += res
  ans2 += res2
print ans,ans2