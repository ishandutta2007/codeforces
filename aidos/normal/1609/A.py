

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    c = 0
    for x in a:
        while x % 2 == 0:
            x //= 2
            c += 1
        b.append(x)
    print(sum(b)+max(b) * (2**c-1))


t = int(input())
for i in range(t):
    solve()