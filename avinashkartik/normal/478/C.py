from math import *
from collections import *
a = list(map(int,input().split()))
a.sort()
if(a[2] > 2*(a[1]+a[0])):
    print(a[1]+a[0])
else:
    print(sum(a)//3)