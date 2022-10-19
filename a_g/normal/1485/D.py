import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

L = 720720
n, m = I()
for i in range(n):
    row = I()
    print(*(L if (i+j)%2 else L-pow(row[j], 4) for j in range(m)))