n = int(input())
ans = None
for i in range(4):
    a, b, c, d = map(int, input().split())
    if min(a, b) + min(c, d) > n:
        continue
    ans = [i + 1, min(a, b), n - min(a, b)]
if ans is None:
    ans = [-1]
print(*ans)