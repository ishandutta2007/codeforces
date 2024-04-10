n = int(input())
a = sorted(map(int, input().split()))
ans = 0
j = 0
for i in range(n):
    while a[j] + 5 < a[i]:
        j += 1

    ans = max(ans, i - j + 1)
print(ans)