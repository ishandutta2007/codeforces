t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	l = [0 for i in range(500)]
	j = 1
	for i in a:
		l[i] = 1
	for i in range(k):
		while(l[j] == 1):
			j += 1
		l[j] = 1
	while(l[j] == 1):
		j += 1
	print(j-1)