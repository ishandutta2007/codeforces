n=input();l=[1]+[0]*n;d=[[]for _ in range(n)];c=[0]
for _ in range(n-1):
  a,b=map(int,raw_input().split());d[a-1]+=[b-1];d[b-1]+=[a-1]
while c:
  x=c.pop()
  for y in d[x]:
    if not l[y]:
      c+=[y];l[y]=-l[x]
r=l.count(1);print(r*(n-r)-n+1)