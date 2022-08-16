from collections import *
from math import *
from sys import *
s = input()
l = [s[0]]
n = len(s)
i = 1
flag = 0
while(i<n):
    if(i < n-3 and s[i:i+3] == "dot"):
        l.append(".")
        i += 3
    elif(flag == 0 and i < n-2 and s[i:i+2] == "at"):
        l.append("@")
        i += 2
        flag = 1
    else:
        l.append(s[i])
        i += 1
print("".join(l))