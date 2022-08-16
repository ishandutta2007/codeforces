from math import *
from collections import *
t = int(input())
for y in range(t):
    a = list(map(int,input().split()))
    x = a[3]//a[2]
    a[3] -= min(x,a[0])*a[2]
    #print(a[3])
    if(a[3] <= a[1]):
        print("YES")
    else:
        print("NO")