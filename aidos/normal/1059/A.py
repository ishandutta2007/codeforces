n, L, a = map(int, input().split())
t = [0] * (n + 2)
l = [0] * (n + 2)
for i in range(1, n + 1):
    t[i], l[i] = map(int, input().split())
t[n+1] = L
ans = 0
for i in range(1, n + 2):
    x = t[i] - t[i-1] - l[i-1]
    ans += x//a
print(ans)