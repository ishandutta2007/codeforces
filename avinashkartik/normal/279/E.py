from math import *
from collections import *
a = list(input())
a = a[::-1]
n = len(a)
ct = 1
i = 0
while(i < n-1):
    #print(i)
    if(a[i] == '0'): 
        i += 1
        continue
    cnt = 0
    while(i < n-1 and a[i] == '1' and a[i+1] == '1'):
        cnt += 1
        i += 1
    if(i == n-1): ct += 1
    else:
        if(cnt != 0):
            a[i+1] = '1'
        ct += 1
        i += 1
print(ct)