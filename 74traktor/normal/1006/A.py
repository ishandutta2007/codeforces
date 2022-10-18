n = int(input())
a = [int(x) for x in input().split()]
for i in range(n):
	print(a[i]- (a[i] + 1) % 2,end = ' ')