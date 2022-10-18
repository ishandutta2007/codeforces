import sys
import itertools

input=sys.stdin.readline

t = int(input())
for z in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	a = [10**18] + a
	p = list(itertools.accumulate(a))
	c = [0] * (n + 1)
	st = [0]
	mn = [2 * a[0]]
	ok = True
	for i in range(1, n+1):
		c[i] = p[i - 1]
		while a[st[-1]] <= a[i]:
			c[i] = min(c[i], c[st[-1]])
			mn.pop()
			st.pop()
		st.append(i)
		mn.append(min(mn[-1], a[i] + c[i]))
		if p[i] > mn[-1]:
		    ok = False
	print('YES' if ok else 'NO')