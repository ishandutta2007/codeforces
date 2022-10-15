import string
import sys
n = input()
a = string.split(raw_input(), ' ')
p = {}
for i in range(len(a)):
	p[int(a[i])] = i
a = string.split(raw_input(), ' ')
for i in range(len(a)):
	sys.stdout.write(repr(p[int(a[i])] + 1) + ' ')