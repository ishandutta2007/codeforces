from math import *
from collections import *
n,k = map(int,input().split())
l = list(map(int,input().split()))
for i in range(n):
    l[i] = [l[i],i+1]
ans = []
for i in range(k):
    l.sort()
    if(l[-1][0] == l[0][0]):
        print(0,i)
        for i in ans:
            print(i[0],i[1])
        break
    l[-1][0] -= 1
    l[0][0] += 1
    ans.append([l[-1][1],l[0][1]])
else:
    l.sort()
    print(l[-1][0]-l[0][0],k)
    for i in ans:
        print(i[0],i[1])