a,b,x=map(int,raw_input().split())
c=1
if a>=b:
	c=0
ans=""
while x>1:
	ans=ans+str(c)
	if c==0:
		a-=1
	if c==1:
		b-=1
	c=1-c
	x-=1
if c == 0:
	ans=ans+"0"*a+"1"*b
else:
	ans=ans+"1"*b+"0"*a
print(ans)