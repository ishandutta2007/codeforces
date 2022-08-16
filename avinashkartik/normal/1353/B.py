t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	ans = 0
	a.sort()
	for i in range(n-1,k-1,-1):
		ans += a[i]
	b += a[:k]
	b.sort(reverse = True)
	for i in range(k):
		ans += b[i]
	print(ans)