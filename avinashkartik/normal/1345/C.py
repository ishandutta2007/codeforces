t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	d = dict()
	flag = 1
	for i in range(n):
		x = (a[i]+i)%n
		if x in d:
			flag = 0
		d[x] = 1
	if(flag == 1):
		print("YES")
	else:
		print("NO")