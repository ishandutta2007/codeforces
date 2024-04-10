n=input()
a=map(int,raw_input().split())

m=input()
b=map(int,raw_input().split())

c=[]

maxv=3*n-3*m
resa=3*n

for i in a:
	c.append((i,-1))
for i in b:
	c.append((i,1))

c.sort()


av=3*n
bv=3*m

for i in c:
	x,y=i
	if y is -1: av-=1
	else: bv-=1
	if av-bv > maxv:
		maxv = av - bv
		resa = av
	if av-bv == maxv:
		if resa<av:
			resa=av
	
	
print "%d:%d"%(resa,resa-maxv)