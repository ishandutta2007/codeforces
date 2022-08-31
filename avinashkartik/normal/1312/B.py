t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	a.sort(reverse = True)
	for i in a:
		print(i,end = " ")
	print()