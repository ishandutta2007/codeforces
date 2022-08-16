t = int(input())
for j in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	a.sort()
	print(a[n]-a[n-1])