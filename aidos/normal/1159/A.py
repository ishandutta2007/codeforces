n = int(input())
m = 0
s = input()
ans = 0
for i in range(n):
    if s[i] == '-':
        ans -= 1
    else:
        ans += 1
    m = min(m, ans)
print(ans - m)