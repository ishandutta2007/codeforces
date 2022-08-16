from math import *
n = int(input())
s = 0
for i in range(5,n+1):
    for j in range(1,i):
        u = i*i - j*j
        if(sqrt(u) == int(sqrt(u))):
            s += 1
print(s//2)