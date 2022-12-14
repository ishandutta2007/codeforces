a1, a2, a3, a4, a5, a6 = map(int, input().split())

ans = 0
cur = a1 * 2 + 1

for i in range(min(a2, a6)):
    ans += cur
    cur += 2

cur -= 1

for i in range(min(a2, a6), max(a2, a6)):
    ans += cur

cur -= 1

for i in range(min(a3, a5)):
    ans += cur
    cur -= 2

print(ans)