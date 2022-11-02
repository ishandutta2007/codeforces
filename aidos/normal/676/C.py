n, k = map(int, input().split())
a = input()
r = 0
b = [ord(x) - ord('a') for x in a]
s = 0
ans = 0
for i in range(n):
    while r < n and ((s + b[r]) <= k or (r + 1 - i - s - b[r]) <=  k):
        s += b[r]
        r += 1
    ans = max(ans, r - i)
    s -= b[i]
    if r == n:
        break
print(ans)