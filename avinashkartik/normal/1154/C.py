from math import *
def calc(i,a,b,c):
	ct = 0
	for j in range(7):
		if(l[i] == 1): 
			if(a == 0): break
			a -= 1
		if(l[i] == 2): 
			if(b == 0): break
			b -= 1
		if(l[i] == 3): 
			if(c == 0): break
			c -= 1
		i = (i+1)%7
		ct += 1
	return ct

a,b,c = list(map(int,input().split()))
l = [1,2,3,1,3,2,1]
x = min(a//3,b//2,c//2)
a -= 3*x
b -= 2*x
c -= 2*x
ans = 7*x
ct = 0
for i in range(7):
	ct = max(ct,calc(i,a,b,c))
print(ans+ct)