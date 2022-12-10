import sys
import time
def is_valid_permutation(perm):
    N = len(perm)
    s = set()
    for x in perm:
        if x >= N or x in s:
            return False
        s.add(x)
    return True
def assert_query_results(p, b, query_results_0i):
    for i in range(len(query_results_0i)):
        if p[0] ^ b[i] != query_results_0i[i]:
            return False
    return True
n = int(raw_input())
xors_0i = []
xors_i0 = []
for i in range(n):
    print "? %i %i" % (0, i)
    sys.stdout.flush()
    xors_0i.append(int(raw_input()))
    print "? %i %i" % (i, 0)
    sys.stdout.flush()
    xors_i0.append(int(raw_input()))
start = time.time()
p, b = [0] * n, [0] * n
p_final = []
count = 0
for i in range(0, n):
    p[0] = i
    for j in range(1, n):
        p[j] = p[0] ^ xors_i0[0] ^ xors_i0[j]

    if not is_valid_permutation(p):
        continue

    for j in range(n):
        b[p[j]] = j

    if assert_query_results(p, b, xors_0i):
        count += 1
        p_final = list(p)

print "!"
print count
if count > 0:
    print ' '.join([str(x) for x in p_final])

end = time.time()