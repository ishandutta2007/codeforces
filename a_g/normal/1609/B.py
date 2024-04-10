I=input
n,q=map(int,I().split())
s=I()
c=s.count('abc')
v=[*s]
while q:
	a,b=I().split();a=int(a)-1;d=1;q-=1
	while d+3:
		if'abc'in''.join(v[max(a-2,0):a+3]):c-=d
		v[a]=b;d-=2
	print(c)