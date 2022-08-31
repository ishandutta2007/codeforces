from math import *

n,m = map(int,input().split())
a = []
for y in range(n):
	a.append(input())
x = [0 for i in range(n)]
t = ""
for i in range(n):
	for j in range(i+1,n):
		if(x[j] == 1 or x[i] == 1): continue
		if(a[i] == a[j][::-1]):
			t = a[i] + t + a[j]
			#print(t)
			x[i] = 1
			x[j] = 1
#print(t)
for i in range(n):
	if(x[i] == 1): continue
	if(a[i] == a[i][::-1]):
		t = t[:len(t)//2]+a[i]+t[len(t)//2:]
		break
print(len(t))
print(t)