mod, sx, sy, dx, dy, t = map(int, raw_input().split())
v = (sx - 1, sy - 1, dx + sx + sy, dy + sx + sy, 1, 1)
A = [
[1, 0, 1, 0, 0, 0],
[0, 1, 0, 1, 0, 0],
[1, 1, 2, 1, 1, 2],
[1, 1, 1, 2, 1, 2],
[0, 0, 0, 0, 1, 1],
[0, 0, 0, 0, 0, 1]
]
I = lambda: [[1 if i == j else 0 for j in xrange(6)] for i in xrange(6)]
def mul(M, N):
    global mod
    res = [[0] * 6 for i in xrange(6)]
    for i in xrange(6):
        for j in xrange(6):
            for k in xrange(6):
                res[i][j] += M[i][k] * N[k][j]
                res[i][j] %= mod
    return res
def power(M, k):
    if k > 1:
        res = power(M, k/2)
        res = mul(res, res)
        if k % 2:
            res = mul(res, M)
        return res
    elif k == 1:
        return M
    else:
        return I()
B = power(A, t)
V = [0] * 6
for i in xrange(6):
    for j in xrange(6):
        V[i] += B[i][j] * v[j]
        V[i] %= mod
print V[0] + 1, V[1] + 1