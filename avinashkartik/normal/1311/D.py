t = int(input())
for y in range(t):
	a,b,c = map(int,input().split())
	m = 1e6
	ans = []
	for i in range(1,2*a+1):
		ct = abs(a-i)
		for j in range(i,2*b+1,i):
			ct1 = abs(b-j)
			C1 = (c//j)*j
			C2 = (c//j+1)*j
			if(C2 < j and C1 < j): continue
			f = 0
			if(C2 >= j): ct2 = abs(c-C2)
			if(C1 >= j): 
				if(ct2 > abs(c-C1)):
					ct2 = abs(c-C1)
					f = 1
			if(ct+ct1+ct2 < m):
				m = ct+ct1+ct2
				ans = [i,j]
				if(f == 1):
					ans.append(C1)
				else:
					ans.append(C2)
	print(m)
	for i in ans:
		print(i,end=" ")
	print()