t = int(input())
for _ in range(t):
    a, b, n = map(int, input().split())
    print([a, b, a^b][n % 3])