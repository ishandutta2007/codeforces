from collections import Counter
n,a,b=map(int,raw_input().split())
s=Counter();l=0
for i in range(n):
	x,vx,vy=map(int,raw_input().split())
	tmp=vy-a*vx
	l+=s[tmp]-s[(vx,vy)]
	s[tmp]+=1;s[(vx,vy)]+=1
print l*2