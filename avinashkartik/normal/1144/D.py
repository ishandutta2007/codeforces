from collections import *
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
m = 0
ind = 0
for i in range(len(a)):
	if(c[a[i]] > m):
		m = c[a[i]]
		ind = i
print(n-m)
for i in range(ind,0,-1):
	if(a[i-1] == a[ind]):
		continue
	if(a[i-1] > a[ind]):
		print(2,i,i+1)
	else:
		print(1,i,i+1)
for i in range(ind,n-1):
	if(a[i+1] == a[ind]):
		continue
	if(a[i+1] > a[ind]):
		print(2,i+2,i+1)
	else:
		print(1,i+2,i+1)