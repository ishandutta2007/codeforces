n = int(input())
a = list(map(int,input().split()))
c = 1
b = [0 for i in range(n)]
a.sort()
for i in range(n):
	if(b[i] == 0):
		b[i] = c
	for j in range(i+1,n):
		if(a[j]%a[i] == 0):
			b[j] = 1
	c += 1
print(len(set(b)))