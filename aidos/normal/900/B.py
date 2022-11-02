a, b, c = map(int, input().split())
d = set()
ans = -1
cnt = 1
while True:
    a *= 10
    g = a//b
    if g == c:
        ans = cnt
        break
    cnt += 1
    a %= b
    if a in d:
        break
    d.add(a)
print(ans)