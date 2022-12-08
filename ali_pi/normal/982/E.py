#!/usr/bin/env python2
[n, m, x, y, vx, vy] = map(int, input().strip().split())
def mygcd(x, y):
	if x > y:
		d, p, q = mygcd(y, x)
		return d, q, p
	if x == 0:
		return y, 0, 1
	m, r = divmod(y, x)
	d, p, q = mygcd(r, x)
	return d, q - p*m, p

def solve(n, m, x, y, vx, vy):
	if vx < 0:
		cx, cy = solve(n, m, n - x, y, -vx, vy)
		if cx < 0:
			return cx, cy
		else:
			return n - cx, cy
	if vy < 0:
		cx, cy = solve(n, m, x, m - y, vx, -vy)
		if cx < 0:
			return cx, cy
		else:
			return cx, m - cy
	if vx == 0:
		if x in (0, n):
			return x, m
		else:
			return -1, -1
	if vy == 0:
		if y in (0, m):
			return n, y
		else:
			return -1, -1
	d, p, q = mygcd(n, m)
	if (x - y) % d != 0:
		return -1, -1
	if x == y and n == m:
		return n, m
	if x == y:
		return ((m // d) % 2) * n, ((n // d) % 2) * m
	mxy = min(x, y)
	x, y = x - mxy, y - mxy
	n //= d
	m //= d
	x //= d
	y //= d
	c = x - y
	p = (p * c) % m
	q = (-q * c) % n
	if p*n - x < 0:
		p += m * (-((x - p*n) // m))
	if q*m - y < 0:
		q += n * (-((y - q*m) // n))
	return (p % 2) * n * d, (q % 2) * m * d
	
cx, cy = solve(n, m, x, y, vx, vy)
if cx < 0:
	print (-1)
else:
	print (cx, cy)