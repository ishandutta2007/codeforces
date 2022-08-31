import sys

n=int(sys.stdin.readline())

res=[]
for a in xrange(100):
	p=2**a-1
	if p > n:
		break
	x=0
	y=10**30
	while y-x>1:
		k=(x+y)//2
		if 2*k*k+(2*p+1)*k+p>n:
			y=k
		else:
			x=k
	k=x
	if 2*k*k+(2*p+1)*k+p==n:
		res.append((k*2+1)*2**a)
res.sort()
if len(res)==0:
	print -1
for k in res:
	print k