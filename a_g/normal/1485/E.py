import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	par = [0,0]+I()
	a = [0,0]+I()
	children = [[] for _ in range(n+1)]
	for i in range(2, n+1):
		children[par[i]].append(i)
	layers = [[1]]
	while 1:
		nextlayer = []
		for v in layers[-1]:
			for u in children[v]:
				nextlayer.append(u)
		if len(nextlayer) == 0:
			break
		layers.append(nextlayer)
	dp = [0]*(n+1)
	for j in range(len(layers)-1, 0, -1):
		M = max(a[u] for u in layers[j])
		m = min(a[u] for u in layers[j])
		X = max(dp[u]+a[u] for u in layers[j])
		Y = max(dp[u]-a[u] for u in layers[j])
		for v in layers[j]:
			dp[v] = max(max(M-a[v], a[v]-m)+dp[v], X-a[v], Y+a[v])
			dp[par[v]] = max(dp[par[v]], dp[v])
	print(dp[1])