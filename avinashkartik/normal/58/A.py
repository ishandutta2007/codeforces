from math import *
from collections import *
import queue
s = input()
n = len(s)
ch = "hello"
ind = 0
for i in range(n):
    if(ind < 5 and s[i] == ch[ind]):
        ind += 1
if(ind == 5):
    print("YES")
else:
    print("NO")