n = int(input())
s = input()
ans=10 ** (n + 3)
a = []
for i in range(1, n):
    if s[i] != '0':
        a.append(i)
i = 0
while i < len(a) and a[i] <= n//2:
    i += 1
for j in range(max(i-3, 0), min(i+3, len(a))):
    ans = min(int(s[:a[j]]) + int(s[a[j]:]), ans)
print(ans)