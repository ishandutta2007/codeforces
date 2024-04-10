# map(int, raw_input().split())
# " ".join([])
# [0] * n
# isupper

n = input()
a, b = 1e9, 0
for x in map(int, raw_input().split()):
	c = min(max(a, b), x)
	a = b
	b = c
print c