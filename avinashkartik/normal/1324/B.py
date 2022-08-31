t = int(input())
for y in range(t):
	d = dict()
	n = int(input())
	a = list(map(int,input().split()))
	prev = -1
	for i in a:
		if i not in d:
			d[i] = 1
		else:
			d[i] += 1
		if (d[i] == 2 and prev != i) or d[i] > 2:
			print("YES")
			break
		prev = i
	else:
		print("NO")