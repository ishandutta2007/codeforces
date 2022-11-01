import sys,os

def sqrt(n):
	l = 0; r= n+1
	while r-l != 1:
		md = (r+l)/2
		if md*md <= n:
			l = md
		else:
			r = md
	return l

n = int(raw_input())
alpha = 1
ans = []

while alpha - 1 <= n:
	b = alpha - 1
	D2 = 4*b*b - 4*b + 8*n + 1
	D = sqrt(D2)
	if D*D == D2:
		C = D - 2*b - 1
		if C >= 0 and C % 4 == 0:
			ans.append((C/2+1) * alpha)
	alpha *= 2

if len(ans) == 0:
	print -1
else:
	ans.sort()
	for i in ans:
		print i