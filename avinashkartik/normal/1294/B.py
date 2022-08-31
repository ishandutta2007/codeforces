t = int(input())
for y in range(t):
	n = int(input())
	a = []
	for i in range(n):
		x,y = map(int,input().split())
		a.append([x,y])
	a.sort()
	s = a[0][0]*'R' + a[0][1]*'U'
	flag = 1
	for i in range(1,n):
		x = a[i][0] - a[i-1][0]
		y = a[i][1] - a[i-1][1]
		if(x < 0 or y < 0):
			flag = 0
			break
		s += x*'R' + y*'U'
	if(flag == 0):
		print("NO")
	else:
		print("YES")
		print(s)