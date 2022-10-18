n,d = map(int,input().split())
k = int(input())
for i in range(k):
	q,w = map(int,input().split())
	if (w - q <= d) and (q - w <= d) and (q + w >= d) and (q + w <= 2 * n - d):
		print("YES")
	else:
		print("NO")