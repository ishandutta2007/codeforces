u,v = map(int,input().split())
if(u > v): print(-1)
elif (v-u)%2 == 1: print(-1)
else:
	x = (v-u)//2
	if(v == 0 and u == 0):
		print(0)
	elif(v == u):
		print(1)
		print(u)
	elif(x^u) == x+u:
		print(2)
		print(x+u,x)
	else:
		print(3)
		print(x,x,u)