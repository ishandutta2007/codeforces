def check(mid):
	l = [0 for i in range(n)]
	for i in b:
		if(i[0] > mid): break
		l[i[1]-1] = i[0]
	v = [0 for i in range(mid+1)]
	for i in range(n):
		v[l[i]] += a[i]
	ct = 0
	for i in range(1,mid+1):
		ct += 1
		if(ct >= v[i]):
			ct -= v[i]
			v[i] = 0
		else:
			v[i] -= ct
			ct = 0
	return ct >= 2*sum(v)

def bs():
	l = 0
	r = 5*10**5
	while(l <= r):
		mid = (l+r)//2
		if(check(mid)):
			r = mid-1
		else:
			l = mid+1
	return r+1

n,m = map(int,input().split())
a = list(map(int,input().split()))
b = []
for i in range(m):
	b.append(list(map(int,input().split())))
b.sort()
print(bs())