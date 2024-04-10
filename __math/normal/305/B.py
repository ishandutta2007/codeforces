from fractions import Fraction

p,q = [int(i) for i in raw_input().split()]
n = int(raw_input())
a = [int(i) for i in raw_input().split()]
a.reverse()
f = Fraction(1,a[0])
for i in a[1:]:
	f = 1 / (i + f)

ok = (Fraction(q,p) == f)
if ok:
	print "YES"
else:
	print "NO"