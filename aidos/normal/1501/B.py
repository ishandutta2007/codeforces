

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-2, -1, -1):
        a[i] = max(a[i], a[i+1] - 1)
    print(' '.join(['1' if x > 0 else '0' for x in a]))

t = int(input())
for i in range(t):
    solve()