t = int(input())

for _ in range(t):
    x, y, a, b = map(int, input().split())
    d = 0
    if a > b:
        a, b = b, a
    if x > y:
        x, y = y, x
    
    ans = min(x//a, y//b)
    if a != b:
        d = (y * b - x * a)//(b * b - a * a)
    
    for k in range(d, d + 2):
        A = x - k * a
        B = y - k * b
        if A >= 0 and B >= 0:
            ans = max(ans, k + min(A//b, B//a))
    print(ans)