from math import *
from decimal import *

def p1(x, y, z):
	return Decimal(log(x, 2)) * Decimal(Decimal(y) ** Decimal(z))
def p2(x, y, z):
	return Decimal(log(x, 2)) * Decimal(Decimal(y) * Decimal(z))
x, y, z = map(float, input().split())
f = [p1(x, y, z), p1(x, z, y), p2(x, y, z), p2(x, z, y), p1(y, x, z), p1(y, z, x), 
p2(y, x, z), p2(y, z, x), p1(z, x, y), p1(z, y, x), p2(z, x, y), p2(z, y, x)]
ans = ['x^y^z', 'x^z^y', '(x^y)^z', '(x^z)^y', 'y^x^z', 'y^z^x', '(y^x)^z', '(y^z)^x','z^x^y', 'z^y^x', '(z^x)^y', '(z^y)^x']
x = 0
eps = 1e-6
for i in range(0, 12):
	if (f[i] > f[x] + Decimal(eps)):
		x = i
print(ans[x])