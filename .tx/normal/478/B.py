import sys

fin = sys.stdin
fout = sys.stdout

n, m = map(int, fin.readline().strip().split())
t1 = n - m + 1
kmax = t1 * (t1 - 1) // 2
t2 = n // m
kmin = t2 * (t2 - 1) // 2 * m + n % m * t2
print(" ".join([str(kmin), str(kmax)]))