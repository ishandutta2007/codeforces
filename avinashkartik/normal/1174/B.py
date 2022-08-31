from math import *
n = int(input())
l = list(map(int,input().split()))
a = [0,0]
for i in l:
    a[i%2] += 1

if(a[0] == 0 or a[1] == 0):
    for i in l:
        print(i,end = " ")
    print()
else:
    l.sort()
    for i in l:
        print(i,end = " ")
    print()