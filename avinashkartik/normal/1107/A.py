n=int(input())
x=[]
y=[]
for i in range(n):
  x.append(int(input()))
  y.append(input())
for i in y:
  a=int(i[0])
  b=int(i[1:])
  if(a<b):
    print("YES")
    print("2")
    print(a,b)
  else:
    print("NO")