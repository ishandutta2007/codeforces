n = int(input())
a = input()
b = input()
ans = 0
for i in range(n):
    d = abs(ord(a[i]) - ord(b[i]))
    ans += min(d, 10-d)
print(ans)