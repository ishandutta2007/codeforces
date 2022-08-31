from collections import *
from math import *
from sys import *
n = int(input())
s = input()
i = j = n//2
while(i >= 0 and j < n):
    if(n%2 == 0):
        if(s[i] == '0' and s[j] == '0'):
            i -= 1
            j += 1
        elif(s[j] == '0'):
            s1 = int(s[:i]) + int(s[i:])
            s2 = -1
            break
        elif(s[i] == '0'):
            s1 = -1
            s2 = int(s[:j]) + int(s[j:])
            break
        else:
            s1 = int(s[:i]) + int(s[i:])
            s2 = int(s[:j]) + int(s[j:])
            break
    if(n%2 == 1):
        if(s[i] == '0' and s[j+1] == '0'):
            j += 1
            i -= 1
        elif(s[j+1] == '0'):
            s1 = int(s[:i]) + int(s[i:])
            s2 = -1
            break
        elif(s[i] == '0'):
            s1 = -1
            s2 = int(s[:j+1]) + int(s[j+1:])
            break
        else:
            s1 = int(s[:i]) + int(s[i:])
            s2 = int(s[:j+1]) + int(s[j+1:])
            break
if(s1 == -1):
    print(s2)
elif(s2 == -1):
    print(s1)
else:
    print(min(s1,s2))