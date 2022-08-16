from math import *
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = ['a' for i in range(n)]
	ct = 0
	ch = -1
	for i in range(1,n):
		if ct >= (k):
			break
		ch = i
		ct += i
	#print(k,ct,ch)
	a[ch] = 'b'
	a[k-ct+ch-1] = 'b'
	print(''.join(a[::-1]))