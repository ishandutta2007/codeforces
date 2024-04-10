n = int(input())

a = ("I hate", "I love")
ans = ''
for i in range(n-1):
    ans += a[i % 2]
    ans += ' that '
ans += a[(n-1) % 2]
ans += ' it'
print(ans)