A, B = map(int, input().split())
x, y, z = map(int, input().split())
c = 2 *x + y
d = z * 3 + y
print(max(c-A, 0) + max(d-B, 0))