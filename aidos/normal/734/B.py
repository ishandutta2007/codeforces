a, b, c, d = map(int, input().split())

print(256* min(a, c, d) + 32 * (min(a - min(a, c, d), b)))