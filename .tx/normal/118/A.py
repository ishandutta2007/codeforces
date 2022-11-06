import sys

inp = sys.stdin

s = inp.readline().strip().lower()
for c in s:
	if not c in ['a', 'e', 'i', 'o', 'u', 'y']:
		print("." + c, end="")