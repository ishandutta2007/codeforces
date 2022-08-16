n,m,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
i,j = 0,0
for i in range(n):
	if a[i]%k != 0:
		break
for j in range(m):
	if b[j]%k != 0:
		break
print(i+j)