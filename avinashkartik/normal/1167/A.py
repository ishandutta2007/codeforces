from collections import *
from math import *
t = int(input())
for y in range(t):
    n = int(input())
    s = input()
    ind = s.find('8')
    if(n-ind >= 11 and ind != -1):
        print("YES")
    else:
        print("NO")