from math import *
test = int(input())
for test_case in range(test):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	pre = [0 for i in range(2*k+2)]
	d = [0 for i in range(2*k+1)]
	for i in range(n//2):
		d[a[i]+a[n-i-1]] += 1
		st = min(a[i],a[n-i-1])+1
		en = max(a[i],a[n-i-1])+k
		pre[st] += 1
		pre[en+1] -= 1
	for i in range(1,2*k+2):
		pre[i] += pre[i-1]
	ans = n//2
	for i in range(2,2*k+1):
		#print(i,pre[i],d[i])
		ct = pre[i] + 2*(n//2-pre[i]) - d[i]
		ans = min(ans,ct)
	print(ans)