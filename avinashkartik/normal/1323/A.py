t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ct = 0
	x = -1
	for i in range(n):
		if(a[i]%2 == 0):
			print(1)
			print(i+1)
			break
		else:
			ct += 1
			if(ct == 1): x = i
			if(ct == 2):
				print(2)
				print(x+1,i+1)
				break
	else:
		print(-1)