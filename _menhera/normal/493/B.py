n=input()
a=[]
b=[]
last=0
for i in range(n):
	x=input()
	if x<0:
		b.append(-x)
		last=-1
	else:
		a.append(x)
		last=1

if sum(a)>sum(b): print "first"
elif sum(a)<sum(b): print "second"
else:
	if a>b: print "first"
	elif a<b: print "second"
	else:
		if last == -1: print "second"
		else: print "first"