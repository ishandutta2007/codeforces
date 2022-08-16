n,m,k = map(int,input().split())
if(k > 4*n*m - 2*n - 2*m):
	print("NO")
	exit(0)
print("YES")
res = []
for i in range(n):
	if(m > 1): res.append([m-1,'R'])
	if(i == 0 and m > 1):
		res.append([m-1,'L'])
	elif(m > 1):
		res.append([m-1,'UDL'])
	if(i != n-1):
		res.append([1,'D'])
if(n > 1): res.append([n-1,'U'])
ans = []
for i in res:
	if(i[0]*len(i[1]) <= k):
		ans.append(i)
		k -= i[0]*len(i[1])
	else:
		if(k//len(i[1])): ans.append([k//len(i[1]),i[1]])
		k %= len(i[1])
		if(k): ans.append([1,i[1][:k]])
		k = 0
	if(k == 0):
		break
print(len(ans))
for i in ans:
	print(*i)