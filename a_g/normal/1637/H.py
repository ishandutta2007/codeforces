# https://codeforces.com/contest/1637/submission/147234483
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

class BIT:
	def __init__(self, n):
		self.n = n+5
		self.arr = [0] * self.n
	def add(self, index):
		while index < self.n:
			self.arr[index] += 1
			index += index & (-index)
	def query(self, index):
		s = 0
		while index > 0:
			s += self.arr[index];
			index -= index & (-index)
		return s

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	invs = 0
	bit = BIT(n)
	for i in range(n-1, -1, -1):
		invs += bit.query(p[i])
		bit.add(p[i])
	c = [0] * n
	for i in range(n):
		c[i] = i + 2 - 2 * p[i]
	c.sort(reverse = True)
	s = 0
	out = [invs]
	for i in range(n):
		s += c[i]
		out.append(invs - s - i * (i + 1) // 2)
	print(*out)