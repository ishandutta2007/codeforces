t = int(input())
for y in range(t):
	n = int(input())
	ans = 0
	while(n >= 10):
		ans += (n//10)*10
		n = n//10 + n%10
	print(ans+n)