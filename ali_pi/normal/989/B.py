n, p = map(int,raw_input().split())
s = raw_input()
for i in range(n):
    if i + p >= n:
        continue
    if s[i] == '.' or s[i + p] == '.' or s[i] != s[i + p]:
        was_lol = s[i] == '.'
        s = s.replace('.', '0')
        if s[i] == s[i + p]:
            if was_lol:
                s = s[:i] + '1' + s[i + 1:]
            else:
                s = s[:i+p] + '1' + s[i+p+1:]
        print(s)
        break
else:
    print('No')