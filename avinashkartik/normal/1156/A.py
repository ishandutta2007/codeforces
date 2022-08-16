from collections import *
from math import *
n = int(input())
a = list(map(int,input().split()))
ct = 0
for i in range(n-1):
    if(a[i] + a[i+1] == 5):
        print("Infinite")
        break
    else:
        if(a[i] + a[i+1] == 3):
            ct += 3
        else:
            ct += 4
    if(i < n-2):
        if(a[i] == 3 and a[i+2] == 2):
            ct -= 1
    #print(ct)
else:
    print("Finite")
    print(ct)