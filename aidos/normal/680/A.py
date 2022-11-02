t = list(map(int, input().split()))
ans = 0
for i in t:
    c = t.count(i)
    if c == 1:
        continue
    ans = max(ans, min(3, c) * i)
print(sum(t) - ans)