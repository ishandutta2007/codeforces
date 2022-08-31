t = int(input())
for y in range(t):
	n,m = list(map(int,input().split()))
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	ind = [0 for i in range(n+1)]
	for i in range(n):
		ind[a[i]] = i
	mx,ans = -1,0
	for i in range(m):
		if(ind[b[i]] > mx):
			mx = ind[b[i]]
			ans += 2*(ind[b[i]]-i)+1
		else: ans += 1
	print(ans)