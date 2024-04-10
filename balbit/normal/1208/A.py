# Elliot Liu
#
# 8-30-2019
#
# test project

T = int(input())

for i in range (T):
	a,b,n = list(map(int, input().split()))

	n %= 3
	if n == 0:
		print(a)
	elif n==1:
		print(b)
	else :
		print(a^b)