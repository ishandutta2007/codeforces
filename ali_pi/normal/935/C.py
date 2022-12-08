import math
def d(x1,y1,x2,y2):
	return math.sqrt(((x1-x2)**2)+((y1-y2)**2))
L=[int(x) for x in raw_input().split()]
if d(L[1],L[2],L[3],L[4])>=L[0]:
	print L[1],L[2],L[0]
else:
	t=0.5*(d(L[1],L[2],L[3],L[4])+L[0])
	a=math.atan2(L[2]-L[4],L[1]-L[3])
	x=L[3]+(t*math.cos(a))
	y=L[4]+(t*math.sin(a))
	print x,y,t