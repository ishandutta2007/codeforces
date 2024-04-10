import sys

inp = sys.stdin

n = int(inp.readline())
for i in range(n):
	s = inp.readline().strip()
	if len(s) > 10:
		s = s[0] + str(len(s) - 2) + s[-1]
	print(s)