t = int(input())
for _ in range(t):
    c, m = map(int, input().split())
    x = m//c
    y = m % c
    print(x * x * (c-y) + (x+1) * (x+1) * y)