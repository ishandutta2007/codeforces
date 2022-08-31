from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

n,m = map(int,input().split())
s = input()
a = [0 for i in range(26)]
l = list(input().split())
for i in l:
    ind = ord(i) - ord('a')
    a[ind] = 1
ch = 0
ans = 0
for i in range(n):
    ind = ord(s[i]) - ord('a')
    if(a[ind] == 1):
        ch += 1
    else:
        ans += ch*(ch+1)//2
        ch = 0
ans += ch*(ch+1)//2
print(ans)