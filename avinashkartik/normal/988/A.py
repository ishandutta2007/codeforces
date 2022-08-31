n,k = map(int,input().split())
a = list(map(int,input().split()))
d = dict()
for i in range(n):
	d[a[i]] = i+1
if(len(d) < k):
	print("NO")
else:
	print("YES")
	print(*list(d.values())[:k])