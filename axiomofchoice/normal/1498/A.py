import math
def ok(n: int):
	sum = 0
	for i in str(n):
		sum += ord(i) - 48
	return math.gcd(sum, n) > 1
T = int(input())
for i in range(T):
	n = int(input())
	while not ok(n):
		n += 1
	print(n)