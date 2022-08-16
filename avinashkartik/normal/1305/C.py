n,m = map(int,input().split())
a = list(map(int,input().split()))
ans = 1
if(n <= m):
	for i in range(n):
		for j in range(i+1,n):
			ans *= abs(a[i]-a[j])
			ans %= m
	print(ans)
else:
	print(0)