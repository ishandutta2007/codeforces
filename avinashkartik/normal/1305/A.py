t = int(input())
for y in range(t):
	n = int(input())
	b = list(map(int,input().split()))
	g = list(map(int,input().split()))
	b.sort()
	g.sort()
	print(*b)
	print(*g)