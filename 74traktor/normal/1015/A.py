n,m = map(int,input().split())
a = [0] * 101
for i in range(n):
	x,y = map(int,input().split())
	for j in range(x,y + 1):
		a[j] = 1
b = []
for i in range(1,m + 1):
	if a[i] == 0:
		b.append(i)
print(len(b))
for x in b:
	print(x,end = ' ')