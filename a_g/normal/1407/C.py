import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def ask(i, j):
    print("?", i, j)
    return int(input())

n, = I()
p = [0]*n
z = 1
for i in range(2, n+1):
    x = ask(z, i)
    y = ask(i, z)
    if x < y:
        p[i-1] = y
    else:
        p[z-1] = x
        z = i
p[z-1] = n
print("!", *p)