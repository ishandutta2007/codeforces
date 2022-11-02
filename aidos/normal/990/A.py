n, m, a, b = map(int, input().split())

print(min((m - n % m) * a, (n % m) * b))