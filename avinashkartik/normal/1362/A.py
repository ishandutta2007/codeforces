from collections import *
t = int(input())
for i in range(t):
	a,b = map(int,input().split())
	ct = 0
	if(a > b):
		while(a%2 == 0 and a > b):
			a //= 2
			ct += 1
		if(a != b):
			print(-1)
			continue
		ans = ct//3 + (ct%3)//2 + (ct%3)%2
		print(ans)
	else:
		while(a < b):
			a *= 2
			ct += 1
		if(a != b):
			print(-1)
			continue
		ans = ct//3 + (ct%3)//2 + (ct%3)%2
		print(ans)