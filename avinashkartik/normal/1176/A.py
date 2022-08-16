from math import *
from collections import *
t = int(input())
for y in range(t):
    n = int(input())
    ct = 0
    while(n%5 == 0):
        n = n//5 * 4
        ct += 1
    while(n%3 == 0):
        n = n//3 * 2
        ct += 1
    while(n%2 == 0):
        n = n//2
        ct += 1
    if(n != 1):
        print(-1)
    else:
        print(ct)