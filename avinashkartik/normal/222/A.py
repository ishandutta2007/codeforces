n,k = map(int,input().split())
a = list(map(int,input().split()))
ch = a[-1]
for i in reversed(range(n)):
	if(a[i] != ch): break
else:
	print(0)
	exit(0)
if(i >= k-1):
	print(-1)
else:
	print(i+1)