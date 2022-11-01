n, bx = map(int, raw_input().split())
lstx = map(int, raw_input().split())
m, by = map(int, raw_input().split())
lsty = map(int, raw_input().split())

A = 0
for i in range(0, n): A += (lstx[i] * (bx**(n-1-i)))
B = 0
for i in range(0, m): B += (lsty[i] * (by**(m-1-i)))

if A > B: print ">"
elif A < B: print "<"
else: print "="