l1 = [2*pow(4,i) for i in range(0,7)]
l2 = [1*pow(4,i) for i in range(0,7)]

a = []
b = []
for i in range(1,101):
	s = bin(i)
	s = list(s)
	c1 = 0
	c2 = 0
	for i in range(len(s)-1,1,-1):
		c1 += (ord(s[i])-ord('0'))*l1[len(s)-1-i]
		c2 += (ord(s[i])-ord('0'))*l2[len(s)-1-i]
	a.append(c1)
	b.append(c2)
print("?",end = " ")
for i in range(100):
	print(a[i],end = " ")

print()
n = int(input())
N = list(bin(n))
for i in range(16-len(N)):
	N.insert(2,'0')
print("?",end = " ")
for i in range(100):
	print(b[i],end = " ")

print()
m = int(input())
M = list(bin(m))
for i in range(16-len(M)):
	M.insert(2,'0')

ans = 0
for i in range(15,1,-1):
	if(i%2 == 1):
		ans += (ord(N[i])-ord('0'))*pow(2,15-i)
	else:
		ans += (ord(M[i])-ord('0'))*pow(2,15-i)

print("!",ans)