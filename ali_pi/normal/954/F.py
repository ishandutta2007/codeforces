from __future__ import print_function, division
from collections import OrderedDict
mod = 1000000007
def mat(s, m):
	t = [[0,0,0],[0,0,0],[0,0,0]]
	for i in xrange(3):
		for j in xrange(3):
			t[i][j] = (s[i][0] * m[0][j] + s[i][1] * m[1][j] + s[i][2] * m[2][j]) % mod
	for i in xrange(3):
		s[i] = t[i][:]
def matmul(matrix, v, times):
	if times == 0:
		return
	tmatrix = [[1,1,0],[1,1,1],[0,1,1]]
	for i in xrange(3):
		if v[i] > 0:
			tmatrix[0][i], tmatrix[1][i], tmatrix[2][i] = 0, 0, 0

	ans = [[1,0,0],[0,1,0],[0,0,1]]
	while times > 0:
		if times % 2 == 1:
			# ans = np.matmul(ans, tmatrix)
			mat(ans, tmatrix)
		# tmatrix = np.matmul(tmatrix, tmatrix)
		mat(tmatrix, tmatrix)
		times //= 2

	mat(matrix, ans)
	# matrix = np.matmul(matrix, ans)
def getans():
	run = {}

	n, m = map(int, raw_input().split())

	for i in xrange(n):
		a, l, r = map(int, raw_input().split())
		if not (l-1 in run):
			run[l-1] = [0, 0, 0]
		run[l-1][a-1] += 1

		if not (r in run):
			run[r] = [0, 0, 0]
		run[r][a-1] -= 1

	current = (0, 0, 0)
	run = OrderedDict(sorted(run.items(), key=lambda t: t[0]))

	for k, v in run.iteritems():
		run[k] = (current[0] + v[0], current[1] + v[1], current[2] + v[2])
		current = run[k]

	init_pos = 1
	current = (0, 0, 0)
	matrix = [[1,0,0],[0,1,0],[0,0,1]]
	for k, v in run.iteritems():
		matmul(matrix, current, k - init_pos)
		current = v
		init_pos = k
	matmul(matrix, current, m - init_pos)
	return matrix[1][1]
ans = getans()
print ("%d" % ans)