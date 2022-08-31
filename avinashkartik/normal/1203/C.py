from math import *

n = int(input())
l = list(map(int,input().split()))
l = list(set(l))
g = l[0]
if(len(l) > 1):
	g = gcd(l[0],l[1])
	for i in range(2,len(l)):
		g = gcd(g,l[i])
count = 0
for i in range(int(sqrt(g)),0,-1):
	if(g%i == 0):
		count += 1
count *= 2
if(sqrt(g) == int(sqrt(g))):
	count -= 1
print(count)