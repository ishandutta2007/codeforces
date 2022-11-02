

def solve():
    n, m = map(int, input().split())
    if max(n, m) == 1:
        print(0)
    elif min(n, m) == 1:
        print(1)
    else:
        print(2)


t = int(input())
for i in range(t):
    solve()