t = int(input())
for _ in range(t):
    a, b, x, y, n = map(int, input().split())
    a1 = a - min(a - x, n)
    n1 = n - min(a - x, n)
    b1 = b - min(b - y, n1)
    
    b2 = b - min(b - y, n)
    n2 = n - min(b - y, n)
    a2 = a - min(a - x, n2)
    print(min(a1 * b1, a2 * b2))