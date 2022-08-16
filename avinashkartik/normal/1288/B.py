from math import *
t = int(input())
for y in range(t):
    n,m = map(int,input().split())
    d = 0
    m1 = m
    while(m > 0):
    	d += 1
    	m //= 10
    #print(d)
    if(10**d - 1 > m1):
    	d -= 1
    print(n*d)