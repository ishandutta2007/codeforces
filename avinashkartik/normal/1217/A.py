t = int(input())
for y in range(t):
	s,i,e = map(int,input().split())
	x = (e + i - s)//2
	#print(x)
	if(x >= 0):
		if(e-x >= 0):
			print(e-x)
		else:
			print(0)
	else:
		print(e+1)