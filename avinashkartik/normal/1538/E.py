test = int(input())
for i in range(test):
	n = int(input())
	d = dict()
	for i in range(n) :
		a = list(input().split())
		if (a[1] == ":=") :
			ct = 0
			if ("haha" in a[2]):
				ct = 1
			lr = a[2]
			m = len(a[2])
			if (m >= 4):
				lr = lr[:3] + '#' + lr[m - 3:]
			d[a[0]] = (lr, ct)
		else :
			l = d[a[2]][0]
			r = d[a[4]][0]
			ct = d[a[2]][1] + d[a[4]][1]
			lr = l + r
			m = len(lr)
			for j in range(m - 3):
				if (lr[j : j + 4] == "haha"):
					ct += 1
			if (m >= 4):
				lr = lr[:3] + '#' + lr[m - 3:]
			d[a[0]] = (lr, ct)
		# print(d[a[0]])
		if (i == n - 1):
			print(d[a[0]][1])