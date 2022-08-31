t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	if(n >= 3):
		ans = 2*m
	elif(n == 2):
		ans = m
	else:
		ans = 0
	print(ans)