n = int(input())
s = input()
ans = s[0]
for i in range(1, n):
    if not(s[i] in 'aeiouy' and s[i - 1] in 'aeiouy'):
        ans += s[i]
print(ans)