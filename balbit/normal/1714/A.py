import sys


def getMin(h,m):
	return h * 60 + m



t = int(input())

for _ in range(t):

	n,H,M = [int(x) for x in input().split()]
	base = getMin(H,M);
	ret = 24 * 60 - 1

	for _bruh in range (n):
		h,m = [int(x) for x in input().split()]
		me = getMin(h,m)
		dif = (me - base + 24 * 60) % (24 * 60)
		ret = min(ret, dif)
	
	print(ret//60, ret%60)