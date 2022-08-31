t = int(input())
for y in range(t):
	n = int(input())
	l = list(map(int,input().split()))
	a,b,ct,pa,pb = 0,0,0,0,0
	i,j = 0,n-1
	while(i <= j):
		ca,cb = 0,0
		ct += 1
		while(i <= j and ca <= pb):
			ca += l[i]
			i += 1
		if(i <= j): ct += 1
		while(i <= j and cb <= ca):
			cb += l[j]
			j -= 1
		a += ca
		b += cb
		pa,pb = ca,cb
	print(ct,a,b)