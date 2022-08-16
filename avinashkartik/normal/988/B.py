n = int(input())
a = []
for i in range(n):
	x = input()
	a.append([len(x),x])
a.sort()
for i in range(1,n):
	if(a[i-1][1] not in a[i][1]):
		print("NO")
		break
else:
	print("YES")
	for i in a:
		print(i[1])