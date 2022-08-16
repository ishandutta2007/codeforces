t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	a.sort()
	ans = [0 for i in range(n)]
	ind = 0
	for i in range((n+1)//2-1,-1,-1):
		ans[ind] = a[i]
		ind += 2
	ind = 1
	for i in range((n+1)//2,n):
		if(ind >= n):
			break
		ans[ind] = a[i]
		ind += 2
	for i in ans:
		print(i,end = " ")
	print()