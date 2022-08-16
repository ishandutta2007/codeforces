from collections import *
N = int(3e6)
prime = [0 for i in range(N+8)]
p = [0 for i in range(N+8)]
ct = 1
i = 2
while(i*i <= N):
	if(prime[i] == 0):
		p[i] = ct
		ct += 1
		for j in range(i*i,N,i):
			if(prime[j] == 0):
				prime[j] = i
	i += 1
for i in range(i,N+8):
	if(prime[i] == 0):
		p[i] = ct
		ct += 1

n = int(input())
n = 2*n
b = list(map(int,input().split()))
b.sort()
d = Counter(b)
a = []
for i in range(n-1,-1,-1):
	if(d[b[i]] == 0): continue
	if(prime[b[i]] == 0):
		a.append(p[b[i]])
		d[p[b[i]]] -= 1
	else:
		a.append(b[i])
		d[b[i]//prime[b[i]]] -= 1
	d[b[i]] -= 1
	#print(b[i],a)
for i in a:
	print(i,end = " ")
print()