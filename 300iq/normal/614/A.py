l, r, k = map(int, input().split())
f = 1
logic = False
while (f <= r):
	if (f >= l):
		print(f, end = " ")
		logic = True
	f *= k
if (logic == False):
	print(-1)