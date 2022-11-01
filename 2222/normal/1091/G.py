import random, sys, math

def sqrt(x):
	sys.stdout.write(f'sqrt {x}\n')
	sys.stdout.flush()
	return int(sys.stdin.readline())

def factorize(n, a):
	for x in a:
		x = math.gcd(x, n)
		if 1 < x < n:
			y = n // x
			return factorize(x, {z % x for z in a}) | factorize(y, {z % y for z in a})
	return {n}
	
n = int(sys.stdin.readline())
a = set()
for k in range(50):
	x = random.getrandbits(1024) % n
	y = sqrt((x * x) % n)
	a.add(n + x - y)

res = factorize(n, a)
print('!', len(res), *res)