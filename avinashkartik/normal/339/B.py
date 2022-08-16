n,m = map(int,input().split())
a = list(map(int,input().split()))
p = 1
ans = 0
for i in range(m):
	if(a[i] >= p):
		ans += a[i]-p
	else:
		ans += n+a[i]-p
	p = a[i]
print(ans)