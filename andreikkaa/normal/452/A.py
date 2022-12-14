import re

n = int(input())
s = input()

l = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

for p in l:
	if len(p) != len(s):
		continue
	for i in range(n):
		if s[i] != p[i] and s[i] != '.':
			break
	else:
		print(p)