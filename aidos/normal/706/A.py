a, b = map(int, input().split())
n = int(input())
ans = 10 ** 30
for i in range(n):
    x, y, v=map(int, input().split())
    x -= a
    y -= b
    x = x ** 2
    y = y ** 2
    
    ans = min(ans, ((x+y) ** 0.5)/v)
print(ans)