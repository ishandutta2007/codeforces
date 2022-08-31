from collections import *
from math import *
t = int(input())
for y in range(t):
    a = [0 for i in range(26)]
    l = list(input())
    for i in l:
        ind = ord(i) - ord('a')
        a[ind] += 1
    l = []
    r = []
    for i in range(26):
        ch = chr(i+ord('a')) 
        if(i%2 == 0):
            l.extend([ch]*a[i])
        else:
            r.extend([ch]*a[i])
    if(len(r) > 0 and len(l) > 0):
        if (abs(ord(r[-1]) - ord(l[0])) == 1) and (abs(ord(l[-1]) - ord(r[0])) == 1):
            print("No answer")
        elif (abs(ord(r[-1]) - ord(l[0])) != 1):
            print("".join(r),end = "")
            print("".join(l))
        else:
            print("".join(l),end = "")
            print("".join(r))
    else:
        print("".join(r),end = "")
        print("".join(l))