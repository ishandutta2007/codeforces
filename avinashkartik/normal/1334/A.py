t = int(input())
for y in range(t):
	n = int(input())
	a = []
	f = 1
	for i in range(n):
		a.append(list(map(int,input().split())))
		if(a[-1][0] < a[-1][1]):
			f = 0
	for i in range(n-1):
		if(a[i][1] > a[i+1][1] or a[i][0] > a[i+1][0]):
			f = 0
			break
		if(a[i+1][0]-a[i+1][1]+a[i][1]-a[i][0] < 0):
			f = 0
			break
	if(f == 1):
		print("YES")
	else:
		print("NO")