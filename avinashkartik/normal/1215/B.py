# cook your dish here
from math import *

def gcd(a,b):
    if (b == 0):
        return(a)
    return gcd(b,a%b)

n = int(input())
l = list(map(int,input().split()))
d = dict()
d1 = dict()
a = [0,0,0]
for i in range(n-1,-1,-1):
    #print(d)
    if(l[i] > 0):
        d1[1] = 1
    else:
        d1[-1] = 1
    for key,val in d.items():
        if(l[i]*key > 0):
            v = 1
        else:
            v = -1
        #print(l[i]*key)
        if v in d1:
            d1[v] += val
        else:
            d1[v] = val
    #print(d1)
    d = d1
    for key,val in d1.items():
        a[key] += val
    d1 = dict()
print(a[2],a[1])