s = input()
s1 = input()
ans = 0
i = 0
while i <= len(s) - len(s1):
    if s[i:i + len(s1)] == s1:
        i += len(s1)
        ans += 1
    else:
        i += 1
print(ans)