t = int(input())
for y in range(t):
	n = int(input())
	l = list(map(int,input().split()))
	x,a = map(int,input().split())
	y,b = map(int,input().split())
	k = int(input())
	ct = 0
	l.sort(reverse = True)
	i = n-1
	ab = 0
	act = 0
	bct = 0
	m1 = min(a,b)
	if(m1 == a):
		x1 = x
		x2 = y
	else:
		x1 = y
		x2 = x
	m2 = max(a,b)
	#print(m1,x1,m2,x2)
	for i in range(1,n+1):
		#print(ct,act)
		if(ct >= k):
			val = i
			break
		if(i % m1 == 0 and i % m2 == 0):
			if(x1 < x2):
				ct += (x1)*l[ab]//100
				ct += (x2-x1)*l[bct+ab]//100
				ct += (x1)*l[act+bct+ab]//100
				ab += 1
			else:
				ct += (x2)*l[ab]//100
				ct += (x1-x2)*l[act+ab]//100
				ct += x2*l[act+bct+ab]//100
				ab += 1
		elif(i % m2 == 0):
			if(x1 < x2):
				ct += (x2-x1)*l[bct+ab]//100
				ct += x1*l[act+bct+ab]//100
				bct += 1
			else:
				ct += x2*l[act+bct+ab]//100
				bct += 1
		elif(i % m1 == 0):
			if(x1 < x2):
				ct += x1*l[act+bct+ab]//100
				act += 1
			else:
				ct += (x1-x2)*l[ab+act]//100
				#print(ct)
				ct += x2*l[act+bct+ab]//100
				act += 1
				#print(ct)
	else:
		if(ct >= k):
			print(n)
		else:
			print(-1)
		continue
	print(val-1)