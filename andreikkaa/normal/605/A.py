n = int(input())

p = list(map(int, input().split()))
q = [0] * n

for i in range(n):
    q[p[i] - 1] = i

ans = 1
cur = 1

for i in range(1, n):
    if q[i - 1] < q[i]:
        cur += 1
    else:
        cur = 1
    ans = max(ans, cur)

print(n - ans)