from collections import *
from math import *
n,k = map(int,input().split())
x = (n-k)//2+1
for i in range(1,n+1):
    if(i%x) == 0:
        print(1,end="")
    else:
        print(0,end="")
print()