t = int(input())
for y in range(t):
	n,s,k = map(int,input().split())
	a = list(map(int,input().split()))
	ans = 0
	d = dict()
	for i in range(k):
		d[a[i]] = 1
	while(True):
		if(s-ans > 0 and s-ans not in d):
			break
		if(s + ans <= n and s+ans not in d):
			break
		ans += 1
	print(ans)