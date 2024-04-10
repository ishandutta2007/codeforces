from math import log
from decimal import Decimal

s = ['x^y^z', 'x^z^y', '(x^y)^z', 'y^x^z', 'y^z^x', '(y^x)^z', 'z^x^y', 'z^y^x', '(z^x)^y']

x, y, z = map(Decimal, input().split())

f = []
f += [(Decimal(log(x)) * (y ** z),  0)]
f += [(Decimal(log(x)) * (z ** y), -1)]
f += [(Decimal(log(x)) * (y *  z), -2)]
f += [(Decimal(log(y)) * (x ** z), -3)]
f += [(Decimal(log(y)) * (z ** x), -4)]
f += [(Decimal(log(y)) * (x *  z), -5)]
f += [(Decimal(log(z)) * (x ** y), -6)]
f += [(Decimal(log(z)) * (y ** x), -7)]
f += [(Decimal(log(z)) * (x *  y), -8)]

f.sort()

print(s[-f[-1][1]])