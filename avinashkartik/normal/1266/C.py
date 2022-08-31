from math import *
r,c = map(int,input().split())
if(r == 1 and c == 1): 
  print(0)
  exit(0)
if(c==1):
  for i in range(r):
    print(i+2)
  exit(0)
a = [r+1+i for i in range(500)]
for i in range(1,r+1):
  for j in range(c):
    print(a[j]*i,end=" ")
  print()