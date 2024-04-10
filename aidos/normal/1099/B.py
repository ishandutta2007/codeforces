n = int(input())
ans = 10 ** 10
for i in range(1, 100100):
    x = (n + i - 1)//i
    ans = min(x + i, ans)
print(ans)