n = input()
a = list(map(int,raw_input().split()))
b = list(map(int,list(raw_input())))
current = 0
l = 10**9 * (-1)
r = 10**9
for i in range(n):
	if(b[i] != current):
		current = b[i]
		if(b[i] == 0):
			r = min(r, min(a[i-4:i+1])-1)
		else:
			l = max(l, max(a[i-4:i+1])+1)
print l,r,
end = " "