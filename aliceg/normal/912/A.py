a, b = map(int, input().split())
x, y, z = map(int, input().split())
a1, b1 = x * 2 + y, z * 3 + y
print(max(a1 - a, 0) + max(b1 - b, 0))