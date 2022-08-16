t = int(input())
for x in range(t):
	n , a , b = map(int,input().split())
	l = list(input())
	s = 0
	i = 0
	while(i<n):
		if(i == 0):
			while(i<n and l[i] != '1'):
				i += 1
				s += a + b
				#print(s)
			s += a 
			#print(s)
			if(i == n):
				s -= a
				break
		if(l[i] == '0'):
			c = 0
			while(i<n and l[i] != '1'):
				c += 1
				i += 1
			#print("c",c)
			if(i == n):
				s += (c+1)*b + (c+1)*a
				break
			elif(c>1):
				s1 = min((c+1)*b+(c+2)*a,(c*2*b+c*a))
				#print("min:", s1)
				s += s1
			else:
				s += 2*b + a
			#print(s)

		if(l[i] == '1'):
			while(l[i] != '0'):
				s += 2*b + a
				#print(s)
				i += 1
			if(i == n-1):
				s += 2*b + 2*a 
				break
		
	print(s + b)