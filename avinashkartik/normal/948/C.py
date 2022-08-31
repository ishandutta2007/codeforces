from math import *
from collections import *

def bs(x,i):
    l = i
    r = n-1
    if(i != 0):
        while(l <= r):
            mid = (l+r)//2
            if(mid == n-1):
                return mid
            if(pre[mid]-pre[i-1] > x and pre[mid-1]-pre[i-1] < x):
                return mid
            if(pre[mid]-pre[i-1] == x):
                return mid
            if(pre[mid]-pre[i-1] > x):
                r = mid - 1
            else:
                l = mid + 1
    else:
        while(l <= r):
            mid = (l+r)//2
            if(mid == n-1):
                return mid
            if(pre[mid] > x and pre[mid-1] < x):
                return mid
            if(pre[mid] == x):
                return mid
            if(pre[mid] > x):
                r = mid - 1
            else:
                l = mid + 1
    return mid

n = int(input())
l = list(map(int,input().split()))
t = list(map(int,input().split()))
pre = [t[0]]
for i in range(1,n):
    pre.append(pre[i-1] + t[i])
dis = [0 for i in range(n)]
val = [0 for i in range(n)]
for i in range(n):
    dis[i] = bs(l[i],i)
    #print(dis[i])
    if dis[i] > 0:
        if i > 0:
            if(l[i] > pre[dis[i]] - pre[i-1]):
                #print(i)
                val[dis[i]] += t[dis[i]]
            else:
                val[dis[i]] += l[i] - pre[dis[i]-1] + pre[i-1]
        else:
            if(l[i] > pre[dis[i]]):
                val[dis[i]] += t[dis[i]]
            else:
                val[dis[i]] += l[i] - pre[dis[i]-1]
    else:
        if(l[i] > pre[dis[i]]):
            val[dis[i]] += t[dis[i]]
        else:
            val[dis[i]] += l[0]
ans = [0 for i in range(n)]
for i in range(n):
    ans[i] += 1
    ans[dis[i]] -= 1
for i in range(1,n):
    ans[i] += ans[i-1]
for i in range(n):
    ans[i] *= t[i]
    ans[i] += val[i]
'''
print(pre)
print(dis)
print(val)
'''
for i in ans:
    print(i,end = " ")
print()