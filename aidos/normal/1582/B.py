

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    print(a.count(1) * (2**(a.count(0))))

t = int(input())
for i in range(t):
    solve()