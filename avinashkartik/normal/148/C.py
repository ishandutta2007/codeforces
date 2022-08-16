n,a,b = map(int,input().split())
ans = [1 for i in range(n)]
p = 2
for i in range(b):
	ans[i+1] = p
	p *= 2
p //= 2
if(b == 0 and  a > n-2 >= 0):
	print(-1)
	exit(0)
if(b == 0):
	b = 1
for i in range(a):
	ans[1+b+i] = p+1
	p += 1
for i in ans:
	print(i,end = " ")