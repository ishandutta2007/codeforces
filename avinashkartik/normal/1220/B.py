from math import *

n = int(input())
l = []
for i in range(n):
    l.append(list(map(int,input().split())))
x = int(sqrt((l[0][2]/l[1][2])*l[0][1]))
print(x,end = " ")
for i in range(1,n):
    print(l[0][i]//x,end = " ")