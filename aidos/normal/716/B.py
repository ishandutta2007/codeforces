s = list(input())
n = len(s)
d = dict()
for i in range(n):
    d[s[i]] = d.get(s[i], 0) + 1
    if i >= 26:
        d[s[i-26]] -= 1
        if d[s[i-26]] == 0:
            d.pop(s[i-26])
    if i >= 25:
        x = d.get('?', 0)
        if x == 0:
            if len(d) == 26:
                for j in range(n):
                    if s[j] == '?':
                        s[j] = 'A'
                print(''.join(s))
                exit(0)
        elif x + len(d) - 1 == 26:
            y = []
            for z in range(26):
                Z = chr(z + ord('A'))
                if Z not in d:
                    y.append(Z)
            for j in range(26):
                if s[i-j] == '?':
                    s[i-j] = y[0]
                    y = y[1:]
            for j in range(n):
                if s[j] == '?':
                    s[j] = 'A'
            print(''.join(s))
            exit(0)
print(-1)