from collections import *
a,b = list(map(int,input().split()))
ct2,ct3 = 0,0
while(a%2 == 0):
	ct2 += 1
	a //= 2
while(a%3 == 0):
	ct3 += 1
	a //= 3
CT2,CT3 = 0,0
while(b%2 == 0):
	CT2 += 1
	b //= 2
while(b%3 == 0):
	CT3 += 1
	b //= 3
if(a != b or ct2 > CT2 or ct3 > CT3):
	print(-1)
else:
	print(CT2+CT3-ct2-ct3)