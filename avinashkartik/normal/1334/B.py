t = int(input())
for y in range(t):	
	n,x = map(int,input().split())
	a = list(map(int,input().split()))
	a.sort()
	suf = [0 for i in range(n)]
	suf[-1] = a[-1]
	for i in range(n-2,-1,-1):
		suf[i] = a[i] + suf[i+1]
	ans = 0
	for i in range(n):
		if suf[i]/(n-i) >= x:
			ans = n-i
			break
	print(ans)