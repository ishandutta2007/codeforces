n = int(input())
a = list(map(int,input().split()))
st = []
f = [-1 for i in range(n)]
e = [n for i in range(n)]
for i in range(n):
	while(len(st) != 0  and a[st[-1]] >= a[i]):
		st.pop()
	if(st != []):
		 f[i] = st[-1]
	st.append(i)
st = []
for i in range(n-1,-1,-1):
	while(len(st) != 0  and a[st[-1]] >= a[i]):
		st.pop()
	if(st != []):
		 e[i] = st[-1]
	st.append(i)
pre = [0 for i in range(n)]
suf = [0 for i in range(n)]
for i in range(n):
	if(f[i] == -1):
		pre[i] = (i+1)*a[i]
	else:
		ind = f[i]
		pre[i] = (i-ind)*a[i] + pre[ind]
for i in range(n-1,-1,-1):
	if(e[i] == n):
		suf[i] = (n-i)*a[i]
	else:
		ind = e[i]
		suf[i] = (ind-i)*a[i] + suf[ind]
m = 0
ind = -1
#print(pre,suf)
for i in range(n):
	x = pre[i]+suf[i]-a[i]
	if(x > m):
		m = x
		ind = i
#print(ind)
i = ind
prev = a[i]
res = []
for j in range(i-1,-1,-1):
	prev = min(a[j],prev)
	res.append(prev)
prev = a[i]
res = res[::-1]
res.append(a[i])
for j in range(i+1,n):
	prev = min(a[j],prev)
	res.append(prev)
for i in res:
	print(i,end = " ")
print()