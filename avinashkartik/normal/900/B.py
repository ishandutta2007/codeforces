a,b,c = map(int,input().split())
a %= b
for i in range(10**6):
	a *= 10
	if(a//b == c):
		print(i+1)
		break
	a %= b
else:
	print(-1)