t = int(input())
for y in range(t):	
	n,l,r = list(map(int,input().split()))
	if(l == n*(n-1)+1):
		print(1)
		continue
	ind = 1
	ct = 1
	while(1):
		if(l < ct):
			break
		ct += (n-ind)*2
		ind += 1
	ind -= 1
	if (ct-l)%2 == 0:
		st = ind
		print(st,end = " ")
		l += 1
	st = n+1
	for i in range(ct-1,l-1,-2):
		st -= 1
	for i in range(l,r+1):
		if(i%2 == 1): print(ind,end = " ")
		else:
			print(st,end = " ")
			st += 1
		if(st == n+1):
			ind += 1
			if(ind == n): ind = 1
			st = ind+1
	print()