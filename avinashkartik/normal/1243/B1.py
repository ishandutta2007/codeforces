from math import *
from collections import *
test = int(input())
for y in range(test):
    n = int(input())
    s = list(input())
    t = list(input())
    ans = []
    for i in range(n):
        if(s[i] != t[i]):
            ans.append(i)
    if(len(ans) == 2 or len(ans) == 0):
        if(s[ans[0]] == s[ans[1]] and t[ans[0]] == t[ans[1]]):
            print("Yes")
        else:
            print("No")
    else:
        print("No")