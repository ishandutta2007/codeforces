ta = int(input())
for x in range(ta):
	n,b,f = map(int,input().split())
	l = list(map(int,input().split()))
	c = n//2
	m1 = max(l)
	if(m1 == l[0]):
		m11 = b
		m2 = l[1]
		m22 = f
	else:
		m11 = f
		m2 = l[0]
		m22 = b
	t = 0
	for i in range(c):
		if(m11):
			t += m1
			m11 -= 1
		elif(m22):
			t += m2
			m22 -= 1
		else:
			break
	print(t)