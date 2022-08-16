n = int(input())
a = []
for i in range(1,n+1):
	a.append(1)
	while(len(a) > 1 and a[-1] == a[-2]):
		v = a.pop()
		a.pop()
		a.append(v+1)
for i in a:
	print(i,end = " ")