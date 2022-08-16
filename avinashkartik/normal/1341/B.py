t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	ct = 0
	for i in range(1,k-1):
		if(a[i] >= a[i-1] and a[i] >= a[i+1]):
			ct += 1
	ans = ct
	lb = 0
	for i in range(k,n):
		if(a[i-1] >= a[i-2] and a[i-1] >= a[i]):
			ct += 1
		if(a[i-k+1] >= a[i-k] and a[i-k+1] >= a[i-k+2]):
			ct -= 1
		if(ct > ans):
			ans = ct
			lb = i-k+1
	print(ans+1,lb+1)