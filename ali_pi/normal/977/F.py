import sys
import math
import bisect
from collections import*
n = int(sys.stdin.readline().strip())
a = list(map(int,sys.stdin.readline().strip().split(' ')))

d = {a[0]:1}
maxsf = 1
idx = 0
for i in range(1,n):
	ai = a[i]
	if ai-1 in d:
		d[ai] = d[ai-1] + 1
	else:
		d[ai] = 1
	if d[ai] >= maxsf:
		maxsf = d[ai]
		idx = i

ans = deque()
ans.appendleft(idx)
last = a[idx]
while idx > 0:
	idx -= 1
	if a[idx] == last - 1:
		last = a[idx]
		ans.appendleft(idx)
print len(ans)
print ' '.join([str(i+1) for i in ans])