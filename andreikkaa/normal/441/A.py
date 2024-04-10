n, v = list(map(int, input().split(" ")))
x = lambda k: int(k) < v 
o = []

for i in range(n):
	
	m = list(map(x, input().split(" ")[1:]))
	if any(m):
		o.append(i + 1)

print(len(o))
for i in o:
	print(i, end=" ")