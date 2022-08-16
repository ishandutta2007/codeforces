from math import *
n = int(input())
s = ceil(n/2)
if(n%2 == 1):
    s = s*(-1)
print(int(s))