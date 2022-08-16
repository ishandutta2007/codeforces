import operator
from math import *
t = int(input())
for y in range(t):
    n,x = map(int,input().split())
    l = []
    c = 0
    for z in range(n):
        d,h = map(int,input().split())
        if(h >= d):
            c += 1
        l.append([d-h,d])
    l.sort()
    s = sorted(l, key = operator.itemgetter(1))
    #print(s[-1],l[-1])
    d = l[-1][0]
    s1 = s[-1][1]
    if(s1 >= x):
        print("1")
    elif(c == n):
        print("-1")
    else:
        count = (x - s1)//d
        #print(count)
        if((x-s1)%d != 0):
            count += 1
        print(count+1)