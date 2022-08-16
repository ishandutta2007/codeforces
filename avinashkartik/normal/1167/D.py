from collections import *
from math import *
n = int(input())
s = list(input())
st = 0
ct = [0,0]
l = []
for i in s:
    if(i == ')'):
        if(ct[0] > ct[1]):
            ct[0] -= 1
            l.append(0)
        else:
            ct[1] -= 1
            l.append(1)

    else:
        if(ct[0] < ct[1]):
            ct[0] += 1
            l.append(0)
        else:
            ct[1] += 1
            l.append(1)
'''
for i in range(n):
    if(l[i] == 0):
        print(s[i],end = "")
print()
for i in range(n):
    if(l[i] == 1):
        print(s[i],end = "")
print()
'''
for i in l:
    print(i,end = "")
print()