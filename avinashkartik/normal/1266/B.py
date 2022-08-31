from math import *
n = int(input())
a = list(map(int,input().split()))
for i in a:
  if(1<=i%14<=6 and i > 6):
    print("YES")
  else:
    print("NO")