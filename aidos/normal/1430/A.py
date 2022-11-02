

def solve():
    n = int(input())
    b, c = 0, 0
    if n % 3 == 1:
        n -= 7
        c += 1
    if n % 3 == 2:
        n -= 5
        b += 1
    if n < 0:
        print(-1)
    else:
        print(n//3, b, c)

t = int(input())
for i in range(t):
    solve()