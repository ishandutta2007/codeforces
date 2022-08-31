t = int(input())
for y in range(t):
	n = int(input())
	l = list(map(int,input().split()))
	d = dict()
	for i in l:
		if i in d:
			d[i] += 1
		else:
			d[i] = 1
	l = list(set(l))
	l.sort()
	#print(l)
	low = 0
	up = len(l)-1
	#print(low,up)
	pro = l[low] * l[up]
	f = 0
	while(low <= up):
		if not (d[l[up]] == d[l[low]] and d[l[up]] % 2 == 0 and l[low]*l[up] == pro):
			f = 1
			break
		up -= 1
		low += 1
	if(f==1):
		print("NO")
	else:
		print("YES")