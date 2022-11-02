n = int(input())
s = list(input())
ans = 0
for i in range(1, n):
    if s[i] == s[i-1]:
        for x in 'RGB':
            if x == s[i-1] or (i + 1 < n and s[i+1] == x):
                continue
            s[i] = x
        ans += 1
print(ans)
print(''.join(s))