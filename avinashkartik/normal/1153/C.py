from collections import *
from math import *
n = int(input())
s = list(input())
ct = s.count('(')
for i in range(n):
    if(s[i] == '?'):
        if(ct < n//2):
            s[i] = '('
            ct += 1
        else:
            s[i] = ')'
ct = 0
#print(s)
for i in range(n):
    if(s[i] == '('):
        ct += 1
    else:
        ct -= 1
    if(ct == 0 and i != n-1):
        print(":(")
        break
    elif(ct != 0 and i == n-1):
        print(":(")
        break
    if(ct < 0):
        print(":(")
        break

else:
    for i in range(n):
        print(s[i],end = "")
    print()