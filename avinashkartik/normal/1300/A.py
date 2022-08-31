t = int(input())
for j in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ct = a.count(0)
	if(sum(a)+ct == 0): ct += 1
	print(ct)