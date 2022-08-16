from math import *
from collections import *
import queue
n = int(input())
l = list(map(int,input().split()))
s = input()
i = 0
while(i < n-1):
    st = i
    while(i < n-1 and s[i] == '1'):
        i += 1
    l[st:i+1] = sorted(l[st:i+1])
    i += 1
if(l == sorted(l)):
    print("YES")
else:
    print("NO")