n = int(input())
b = list(map(int,input().split()))
a = [0 for i in range(n)]
x = [0 for i in range(n)]
a[0] = b[0]
x[0] = 0
for i in range(1,n):
	x[i] = max(a[i-1],x[i-1])
	a[i] = b[i]+x[i]
for i in range(n):
	print(a[i],end = " ")
print()