import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, k = I()
    ans = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(k):
        r = i%n
        c = (i+i//n)%n
        ans[r][c] = 1
    print(0 if k%n == 0 else 2)
    for row in ans:
        print(''.join([str(x) for x in row]))