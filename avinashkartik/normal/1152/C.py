from math import *
def fact(a):
    i = 1
    while(i*i <= a):
        if(a%i == 0):
            l.append(i)
            if(i*i != a):
                l.append(a/i)
        i += 1

a,b = map(int,input().split())
if(a > b):
    a,b = b,a
l = []
g = 1e18
ans = 0
fact(b-a)
for i in l:
    k = (ceil(a/i)*i) - a
    if(((a+k)*(b+k))/i < g):
        g = ((a+k)*(b+k))/i
        ans = k
print(int(ans))