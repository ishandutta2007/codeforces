w, h, k = map(int, input().split())
ans = 0
for i in range(k):
    ans +=2*(w - 4 * i + h - 4 * i)-4
print(ans)