t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    t = list(input())
    a = []
    for i in range(n):
        if s[i] == t[i]:
            continue
        j = i + 1
        while j < n and t[i] != t[j]:
            j += 1
        if j < n:
            t[j], s[i] = s[i], t[j]
            a.append([i+1, j+1])
            continue
        j = i + 1
        while j < n and t[i] != s[j]:
            j += 1
        if j < n:
            t[i], s[i] = s[i], t[i]
            a.append([i+1, i+1])
            t[i], s[j] = s[j], t[i]
            a.append([j+1, i+1])
    if s != t:
        print('No')
        continue
    print('Yes')
    print(len(a))
    for x in a:
        print(x[0], x[1])