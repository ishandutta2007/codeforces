import sys

input = sys.stdin.readline

def solve(a, b, c):
	if a == b == c:
		return True
	if a == b:
		return solve(c, c, a)
	if b == c:
		return solve(a, a, b)
	if a == c:
		return solve(b, b, a)
	if a < b < c:
		return solve(b, c, a)
	if a < c < b:
		return solve(c, b, a)
	if b < a < c:
		return solve(a, c, b)
	if b < c < a:
		return solve(c, a, b)
	if c < a < b:
		return solve(a, b, c)
	if c < b < a:
		return solve(b, a, c)
	return False

for nt in range(int(input())):
	l = list(map(int,input().split()))
	if sum(l) % 2 == 1:
		print ("NO")
		continue
	l.sort()
	if l[0] == l[1] and l[2] % 2 == 0:
		print ("YES")
		continue
	if l[1] == l[2] and l[0] % 2 == 0:
		print ("YES")
		continue
	if l[0] == l[2]:
		print ("YES")
		continue
	if l[0] + l[1] == l[2]:
		print ("YES")
		continue
	print ("NO")