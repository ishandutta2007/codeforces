from collections import *
from math import *
from sys import *
s = input()
n = len(s)
ct = 0
ans = 0
for i in range(n-4):
    if(s[i:i+5] == "heavy"):
        ct += 1
    elif(s[i:i+5] == "metal"):
        ans += ct
print(ans)