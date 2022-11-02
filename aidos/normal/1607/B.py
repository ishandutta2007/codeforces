


def solve():
    x, n = map(int, input().split())
    a = 0
    if n % 4 == 1:
        a -= n
    elif n % 4 == 2:
        a += 1
    elif n % 4 == 3:
        a += n + 1
    if x % 2 == 1:
        x -= a
    else:
        x += a
    print(x)



t = int(input())
for i in range(t):
    solve()