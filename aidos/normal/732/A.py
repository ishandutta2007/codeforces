n, r = map(int, input().split())

ans = 1
while (ans * n) % 10 != 0 and (ans * n) % 10 != r:
    ans += 1
print(ans)