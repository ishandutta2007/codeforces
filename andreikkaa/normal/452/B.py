n, m = list(map(int, input().split()))

l = [(0, 0), (1, 0), (0, 1), (1, 1), (n, 0), (n - 1, 0), (n, 1), (n - 1, 1), (0, m), (1, m), (0, m - 1), (1, m - 1), (n, m), (n - 1, m), (n, m - 1), (n - 1, m - 1)]
#print(len(l))

o = []

for p in l:
	#print(p, n, m, p[0], p[1])
	if 0 <= p[0] <= n and 0 <= p[1] <= m and not [p, False] in o:
		o.append([p, False])

#print(o)


mz = [False]
ml = 0
z = [True for i in range(4)]
def r(c):
	if c == 4:
		l = 0
		for i in range(1, 4):
			l += ((z[i][0] - z[i - 1][0]) ** 2 + (z[i][1] - z[i - 1][1]) ** 2) ** 0.5	
			#print(i, l)
		if l > ml:
			#print("lol")
			global ml
			global mz
			ml = l
			mz = z[:]
			#print("mz", mz)
		return
	for i in range(len(o)):
		if not o[i][1]:
			o[i][1] = True
			z[c] = o[i][0]
			r(c + 1)
			o[i][1] = False 

	#print(mz)
r(0)
#print(mz)
for i in mz:
	print(i[0], i[1])