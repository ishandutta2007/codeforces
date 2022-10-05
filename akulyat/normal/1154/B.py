n=int(input())
m=input().split()
for i in range(len(m)):
  m[i]=int(m[i])
mi=min(m)
ma=max(m)
if (ma-mi)%2==0:
  d=(ma-mi)//2
  l=set()
  l.add(mi+d)
  for i in m:
    if i<mi+d:
      l.add(i+d)
    elif i>mi+d:
      l.add(i-d)
  if len(l)<=1:
    print(d)
    exit(0)
l=set()
d=ma-mi
l.add(ma)
for i in m:
  if i<ma:
    l.add(i+d)
if len(l)<=1:
  print(d)
  exit(0)
print(-1)