from collections import *
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
print(max(c.values()))