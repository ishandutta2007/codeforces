from sets import Set
home=raw_input()
away=raw_input()
N=input()
arr=Set()
red=Set()
for i in range(N):
	a=raw_input().split()
	if a[1]+a[2] in arr:
		if a[1]+a[2] not in red:
			if a[1]=='a':
				print away,a[2],a[0]
			else:
				print home,a[2],a[0]
			red.add(a[1]+a[2])
	else:
		if a[3]=='r':
			if a[1]=='a':
				print away,a[2],a[0]
			else:
				print home,a[2],a[0]
			red.add(a[1]+a[2])
			arr.add(a[1]+a[2])
		else:
			arr.add(a[1]+a[2])