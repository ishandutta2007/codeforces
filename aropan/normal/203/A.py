x, t, a, b, da, db = map(int, raw_input().split())
if x == 0 or (x - a) % da == 0 and 0 <= -(x - a) / da and -(x - a) / da < t or (x - b) % db == 0 and 0 <= -(x - b) / db and -(x - b) / db < t:
	print "YES"
	exit(0)
for i in xrange(0, t):
	if x - (a - da * i) < 0:
		continue;
	if (x - (a - da * i) - b) % db:
		continue
	j = -(x - (a - da * i) - b) / db
	if j < 0 or t <= j:
		continue;
	print "YES"
	exit(0)
print "NO"
exit(0)