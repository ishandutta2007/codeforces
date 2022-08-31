from collections import *
from math import *
a,b = map(int,input().split())
if(a == b):
    print(a*10,a*10+1)
elif(a == b-1):
    print(b*10-1,b*10)
elif(a == 9 and b == 1):
    print(9,10)
else:
    print(-1)