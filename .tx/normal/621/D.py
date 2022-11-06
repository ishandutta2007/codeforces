from decimal import *

x, y, z = map(Decimal, input().split(' '))

getcontext().prec = 100

a = [0] * 9
a[0] = x.ln() * (y ** z)
a[1] = x.ln() * (z ** y)
a[2] = x.ln() * y * z
a[3] = y.ln() * (x ** z)
a[4] = y.ln() * (z ** x)
a[5] = y.ln() * x * z
a[6] = z.ln() * (x ** y)
a[7] = z.ln() * (y ** x)
a[8] = z.ln() * x * y

mx = 0

for i in range(9):
    if abs(a[i] - a[mx]) > Decimal(10) ** (-50) and a[i] > a[mx]:
        mx = i

s = [""] * 9
s[0] = "x^y^z"
s[1] = "x^z^y"
s[2] = "(x^y)^z"
s[3] = "y^x^z"
s[4] = "y^z^x"
s[5] = "(y^x)^z"
s[6] = "z^x^y"
s[7] = "z^y^x"
s[8] = "(z^x)^y"

print(s[mx])