t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    x = min(b, c//2)
    y = min((b-x)//2, a)
    print(3*(x + y))