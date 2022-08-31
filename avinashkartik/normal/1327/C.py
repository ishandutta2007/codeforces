n,m,k = map(int,input().split())
for i in range(k):
	x,y = map(int,input().split())
for i in range(k):
	x,y = map(int,input().split())
print((m+n)+n*m-3)
print((m-1)*'L',end = "")
print((n-1)*'U',end = "")
for i in range(m):
	if(i%2 == 0): print((n-1)*'D',end = "")
	else: print((n-1)*'U',end = "")
	if(i < m-1): print('R',end = "")