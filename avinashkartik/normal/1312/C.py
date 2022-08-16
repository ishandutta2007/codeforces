t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	a = list(map(int,input().split()))
	d = dict()
	if(m == 1):
		print("YES")
		continue
	for i in range(n):
		j = 0
		while(a[i]):
			val = a[i]%m
			if(j not in d): d[j] = 0
			d[j] += val
			a[i] //= m
			j += 1
	f = 1
	for v in d.values():
		#print(v)
		if(v > 1): f = 0
	if(f == 0):
		print("NO")
	else:
		print("YES")