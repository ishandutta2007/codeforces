n,m = map(int,input().split())
ct = [0 for i in range(n)]
a = []
for i in range(m):
	a.append(list(map(int,input().split())))
for i in range(m):
	w = -1
	maxx = -1
	for j in range(n):
		if(a[i][j] > maxx):
			maxx = a[i][j]
			w = j
	ct[w] += 1
w = -1
maxx = 0
for i in range(n):
	if(ct[i] > maxx):
		maxx = ct[i]
		w = i
print(w+1)