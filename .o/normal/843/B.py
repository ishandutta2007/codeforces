import sys

n, start, x = map(int, input().split())
C = min(n, 998)

def get(i):
    sys.stdout.write("? %d\n" % i)
    sys.stdout.flush()
    return list(map(int, sys.stdin.readline().split()))

def answer(a):
    print("! %d" % a)
    exit(0)

m = get(start)[0]
if m >= x:
    answer(m)

from random import sample
queries = [get(i) for i in sample(range(1, n+1), C)] + [get(start)]

u = max([q for q in queries if q[0] < x])[1]
while u > 0:
    q = get(u)
    if q[0] >= x: answer(q[0])
    u = q[1]
answer(-1)