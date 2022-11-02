n, k = map(int, input().split())
a = []
for _ in range(n):
    a.append(int(input()))
c = [0] * k
for x in a:
    c[x-1] += 1
ans = 0
for i in range(k):
    ans += c[i]//2 * 2
    c[i] %= 2
ans += (sum(c) + 1)//2
print(ans)