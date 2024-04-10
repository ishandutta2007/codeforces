n, v = map(int, input().split())
cur = 0
ans = 0
for i in range(n):
    need = max(min(n - 1 - i-cur, v-cur), 0)
    cur += need
    ans += (i + 1) * need
    cur -= 1
print(ans)