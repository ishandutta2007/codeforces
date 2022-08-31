from math import *
n = int(input())
s = list(input())
ct = 1
prev = 1
s1 = 0
a = []
for i in range(1,n):
	if(s[i] != s[i-1]):
		a.append(ct)
		#s1 += 1 - ct - prev
		prev = ct
		ct = 1
	else:
		ct += 1
a.append(ct)

#print(s1,a)
s2 = 0
for i in range(0,len(a)):
	s1 -= 2*a[i]
	s1 -= a[i]/2
	s2 += a[i]
s1 += s2*s2/2
s1 += len(a)-1+a[0]+a[-1]
print(int(s1))