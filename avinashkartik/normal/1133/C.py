from collections import *
from math import *
n = int(input())
a = list(map(int,input().split()))
a.sort()
j = n-1
ans = 0
for i in range(n-1,-1,-1):
	while(j >= 0 and a[i] - a[j] <= 5): j -= 1
	ans = max(ans,i-j)
print(ans)