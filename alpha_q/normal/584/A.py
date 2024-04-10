n, t = map(int, raw_input().split())
if n == 1 and t == 10: print -1
else:
	if n == 1: print t
	else:
		num = 10**(n-1)
		for i in range (num, num + 11):
			if i % t == 0:
				print i
				break