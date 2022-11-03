v1, v2, v3, vm = map(int, input().split())
a, b, c = 2 * v1, 2 * v2, min(2 * vm, 2 * v3)
if not(min(v3, vm) * 2 >= c >= max(v3, vm)) or v1 <= vm or v2 <= vm:
    print(-1)
else:
    print(a)
    print(b)
    print(c)