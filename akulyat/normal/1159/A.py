n=int(input())
s=input()
now=0
ans=0
for i in range(n-1, -1, -1):
  if s[i]=='+':
    now+=1
  else:
    now-=1
  ans=max(ans, now)
print(ans)