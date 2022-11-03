n = int(input())
s = input()
f = 0
f1 = 0
for i in range(len(s)):
    if s[i] == '?':
        if i == 0 or i == len(s) - 1 or (i != 0 and i != len(s) - 1 and (s[i - 1] == '?' or s[i + 1] == '?' or s[i - 1] == s[i + 1])):
            f = 1
    else:
        if i != 0 and s[i - 1] == s[i]:
            f1 = 1
if f1:
    print('No')
elif f:
    print('Yes')
else:
    print('No')