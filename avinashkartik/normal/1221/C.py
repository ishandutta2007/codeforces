from math import *
t = int(input())
for y in range(t):
    c,m,n = map(int,input().split())
    x = min(c,m,(c+m+n)//3)
    print(x)