t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	print(len(set(a)))