k = int(input())
d = dict()
for y in range(1,k+1):
	d1 = dict()
	n = int(input())
	a = list(map(int,input().split()))
	s = sum(a)
	for i in range(n):
		x = s-a[i]
		if(x in d):
			print("YES")
			print(*d[x])
			print(y,i+1)
			exit(0)
		d1[x] = [y,i+1]
	for i in d1.keys():
		d[i] = d1[i]
print("NO")