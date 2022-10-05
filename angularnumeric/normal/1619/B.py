import sys

t = int(input())
for _ in range(t):
    n = int(input())
    a = set()
    for i in range(1, n + 1):
        a.add(i * i)
        if i ** 2 > n:
            break
    b = set()
    for i in range(1, n + 1):
        b.add(i * i * i)
        if i ** 3 > n:
            break
    c = a | b
    ans = 0
    for i in sorted(c):
        if i > n:
            break
        ans += 1
    print(ans)