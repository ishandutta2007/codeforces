import math
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
cta,ctb = 0,1
for i in range(n):
	if(a[i] > b[i]):
		cta += 1
	elif(b[i] > a[i]):
		ctb += 1
if(cta == 0):
	print(-1)
else:
	print(math.ceil(ctb/cta))