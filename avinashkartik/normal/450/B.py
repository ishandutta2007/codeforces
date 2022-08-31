from math import *
x,y = map(int,input().split())
mod = 10**9+7
a = [x,y,y-x,-x,-y,x-y]
n = int(input())
print(a[(n-1)%6]%mod)