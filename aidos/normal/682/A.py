n, m = map(int, input().split())
nn = n + (5-n%5)%5
mm = m + (5-m%5) % 5
ans = (nn * mm) // 5 - (mm - m) * nn//5 - (nn-n) * mm//5
for i in range(n+1, nn + 1):
    j = i % 5
    if mm - j > m:
        ans += 1
print(ans)