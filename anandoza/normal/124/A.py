n, a, b = tuple(int(i) for i in raw_input().split())

print min(n - a, b + 1)