t = int(input())
for y in range(t):
	a = list(map(int,input().split()))
	a.sort()
	if(a[2] > a[0]+a[1]):
		print("No")
	else:
		print("Yes")