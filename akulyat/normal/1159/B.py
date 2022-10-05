n=int(input())
m=input().split()
for i in range(n):
  m[i]=int(m[i])
ans=1000000000000
for i in range(n):
  dist=max(i, n-1-i)
  ans=min(ans, m[i]//dist)
print(ans)