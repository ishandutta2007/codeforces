r=range
I=lambda:[*map(int,input().split())]
n,q=I()
Q=99
p=[0]+I()
v=[*p]
P=[*r(n+1)]
for i in P:
	v[p[i]]=i
	for _ in r(Q):P[i]=p[P[i]]
while q:
	a,b,c=I();q-=1
	if a>1:
		while c>=Q:b=P[b];c-=Q
		while c:b=p[b];c-=1
		print(b)
	else:
		d,e=p[b],p[c];p[b],p[c]=e,d;v[d],v[e]=c,b
		for i in r(Q-1):b,c=v[b],v[c]
		for j in r(Q):P[b],P[c]=e,d;b,c,e,d=p[b],p[c],p[e],p[d]