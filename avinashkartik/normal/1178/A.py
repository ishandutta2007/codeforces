from collections import *
from math import *
n = int(input())
l = list(map(int,input().split()))
b = [0]
s = l[0]
for i in range(1,n):
    if l[i] <= l[0]//2:
        s += l[i]
        b.append(i)
if s > sum(l)//2:
    print(len(b))
    for i in b:
        print(i+1,end = " ")
else:
    print(0)