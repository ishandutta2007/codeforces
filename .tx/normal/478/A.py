import sys

fin = sys.stdin
fout = sys.stdout

s = sum(map(int, fin.readline().strip().split()))
print("-1" if s == 0 or s % 5 != 0 else str(s // 5), file=fout)