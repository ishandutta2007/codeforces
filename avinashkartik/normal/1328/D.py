from math import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ans = [0 for i in range(n)]
	if len(set(a)) == 1:
		print(1)
		print("1 "*n)
	else:
		if(n%2 == 0):
			print(2)
			print("1 2 "*(n//2))
		else:
			f = 0
			v = 0
			for i in range(n):
				ans[i] = v+1
				v = v^1
				if i != n-1:
				 	if(f == 0 and a[i] == a[i+1]):
				 		f = 1
				 		v ^= 1
				else:
					if(f == 0 and a[0] == a[-1]):
						f = 1
			if(f == 0):
				ans[n-1] = 3
				print(3)
			else:
				print(2)
			for i in ans:
				print(i,end = " ")
			print()