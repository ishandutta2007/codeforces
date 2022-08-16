test = int(input())
for yy in range(test):
	x,y = map(int,input().split())
	a,b = map(int,input().split())
	x = abs(x)
	y = abs(y)
	ctb = min(x,y)
	cta = max(x,y)-min(x,y)
	print(min(cta*a+ctb*b,(x+y)*a))