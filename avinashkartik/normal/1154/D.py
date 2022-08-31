from math import *
n,b,a = map(int,input().split())
ma = a
mb = b
l = list(map(int,input().split()))
for i in range(n):
  #print(a,b,l[i])
  if(l[i] == 1 and b != 0 and a!= ma):
    a = min(a+1,ma)
    b -= 1
  elif(l[i] == 1):
    a -= 1
  elif(l[i] == 0 and a != 0):
    a -= 1
  else:
    b -= 1
  if(a+b == 0): break
print(i+1)