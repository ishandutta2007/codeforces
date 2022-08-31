from math import *
from collections import *
n = int(input())
l = []
for i in range(n):
    s = input()
    l.append(s[0])
l = Counter(l)
ans = 0
for i in l.values():
    x = i//2
    y = i-x
    ans += x*(x-1)//2 + y*(y-1)//2
print(ans)