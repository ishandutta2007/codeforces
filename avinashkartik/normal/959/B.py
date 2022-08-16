n,k,m = map(int,input().split())
a = list(input().split())
ind = dict()
for i in range(n):
	ind[a[i]] = i+1
l = [0]+list(map(int,input().split()))
d = dict()
for y in range(k):
	b = list(map(int,input().split()))
	for j in range(1,len(b)):
		d[b[j]] = b[1]
		l[b[1]] = min(l[b[1]],l[b[j]])
b = list(input().split())
ans = 0
for i in range(m):
	j = ind[b[i]]
	ans += l[d[j]]
print(ans)