t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	i,j = 0,n-1
	fi = fj = 1
	while(i <= j):
		if(i == j-1 and a[i] == i and a[j] == n-j-1):
			fi = fj = 0
		if(a[i] >= i and fi):
			i += 1
		else:
			fi = 0
		if(a[j] >= n-1-j and fj):
			j -= 1
		else:
			fj = 0
		if(fi == 0 and fj == 0):
			print("No")
			break
	else:
		print("Yes")