t = int(input())
for y in range(t):
	n,m,k = map(int,input().split())
	a = list(map(int,input().split()))
	if(k >= m-1):
		ans = max(max(a[:m]),max(a[n-m:]))
	else:
		i = k
		j = 0
		ans = 0
		while(i >= 0):
			ind1 = i+(m-k)-1
			ind2 = n-j-1
			#print(i,j,ind1,ind2)
			res2 = 1e9
			for kk in range(m-k):
				res = max(a[ind1-kk],a[ind2-kk])
				res2 = min(res,res2)
			ans = max(ans,res2)
			i -= 1
			j += 1
	print(ans)