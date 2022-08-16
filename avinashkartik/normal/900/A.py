t = int(input())
p,n = 0,0
for i in range(t):
	x,y = map(int,input().split())
	if(x < 0): n += 1
	else: p += 1
if(p <= 1 or n <= 1):
	print("Yes")
else:
	print("No")