s = input()

ans = 0
for i in range(len(s)):
    for j in ['V', 'K']:
        t = s[:i] + j + s[i + 1:]
        cur = 0
        for k in range(len(s) - 1):
            if t[k] == 'V' and t[k + 1] == 'K':
                cur += 1
        ans = max(ans, cur)
print(ans)