# map(int, raw_input().split())
# " ".join([])
# [0] * n
# isupper
from fractions import gcd
m = input()
for x in map(int, raw_input().split()):
	print 4 * x / gcd(x + 1, 4 * x) + 1