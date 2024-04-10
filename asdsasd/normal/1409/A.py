t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    c = abs(a - b)
    print((c + 9) // 10)