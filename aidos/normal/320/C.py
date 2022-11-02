s = input()
s = s[::-1]
ans = 0
for i in range(len(s)):
    if s[i] == '1':
        ans += ((2 ** i) ** 2) * (2**(len(s) - i - 1))
print(ans % (10**9+7))