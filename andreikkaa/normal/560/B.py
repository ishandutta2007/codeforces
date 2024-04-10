a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

def f(a, b, c, d):
    if a + c <= a1 and max(b, d) <= b1:
        print("YES")
        exit(0)

for _ in range(2):
    f(a2, b2, a3, b3)
    f(b2, a2, a3, b3)
    f(a2, b2, b3, a3)
    f(b2, a2, b3, a3)
    a1, b1 = b1, a1

print("NO")