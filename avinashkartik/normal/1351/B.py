t = int(input())
for y in range(t):
	a1,b1 = map(int,input().split())
	a2,b2 = map(int,input().split())
	if(a1 == a2):
		if(b1+b2 == a1):
			print("YES")
			continue
	if(a1 == b2):
		if(b1+a2 == a1):
			print("YES")
			continue
	if(b1 == a2):
		if(a1+b2 == b1):
			print("YES")
			continue
	if(b1 == b2):
		if(a1+a2 == b1):
			print("YES")
			continue
	print("NO")