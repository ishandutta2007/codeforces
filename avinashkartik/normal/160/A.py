from math import *
n = int(input())
a = list(map(int,input().split()))
a.sort()
for i in range(n):
	if(sum(a[:i]) < sum(a[i:])):
		ans = n-i
print(ans)