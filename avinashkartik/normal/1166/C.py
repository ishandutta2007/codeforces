from math import *
from collections import *
n = int(input())
l = list(map(int,input().split()))
for i in range(n):
    l[i] = abs(l[i])
l.sort()
j = n-2
ans = [0 for i in range(n)]
for i in range(n-1,-1,-1):
    while(j > -1 and l[j] >= l[i]/2):
        j -= 1
    ans[i] = i-j-1
print(sum(ans))