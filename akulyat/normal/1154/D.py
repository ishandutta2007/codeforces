n, b, a=map(int, input().split())
sa=a
m=input().split()
for i in range(n):
  m[i]=int(m[i])
for i in range(n):
  #print("Use", b, a)
  if a==0 and b==0:
    print(i)
    exit(0)
  if m[i]==1 and a!=sa:
    if b>0:
      a+=1
      b-=1
    else:
      a-=1
  else:
    if a>0:
      a-=1
    else:
      b-=1
else:
  print(n)