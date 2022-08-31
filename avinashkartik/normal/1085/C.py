def path(a,b):
	x,y = a
	fx,fy = b
	f1,f2 = 1,1
	if(fx < x):
		f1 = -1
	if(fy < y):
		f2 = -1
	p1,p2 = [],[]
	for i in range(x,fx+f1,f1):
		p1.append([i,y])
	for i in range(y+f2,fy+f2,f2):
		p1.append([fx,i])
	for i in range(y,fy+f2,f2):
		p2.append([x,i])
	for i in range(x+f1,fx+f1,f1):
		p2.append([i,fy])
	return p1,p2

def merge(p1,p2):
	p3 = p1[:]
	for i in p2:
		if i not in p3:
			p3.append(i)
	return p3

l = []
for i in range(3):
	l.append(list(map(int,input().split())))
l.sort()
p1,p2 = path(l[0],l[1])
p3,p4 = path(l[1],l[2])
p5 = merge(p1,p3)
p6 = merge(p1,p4)
if(len(p6) < len(p5)):
	p5 = p6[::]
p6 = merge(p2,p3)
if(len(p6) < len(p5)):
	p5 = p6[::]
p6 = merge(p2,p4)
if(len(p6) < len(p5)):
	p5 = p6[::]
print(len(p5))
for i in p5:
	print(*i)