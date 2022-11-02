n = int(input())
a = map(int, input().split())
c = [0] * 105
ans = 0
sum = 0
for x in a:
    c[x] += 1
    sum += x
ans = sum
for i in range(101):
    for j in range(i + 1, 101):
        if c[i] > 0 and c[j] > 0:
            for k in range(1, j):
                if j % k == 0:
                    ans = min(ans, sum - i - j + j//k + i * k)

print(ans)