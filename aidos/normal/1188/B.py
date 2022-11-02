n, p, k = map(int, input().split())

a = list(map(int, input().split()))

b = dict()

ans = 0
for i in a:
    j = (i ** 4 - k * i) % p
    c = b.get(j, 0)
    ans += c
    b[j] = c + 1
print(ans)