t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    t = input()
    a = []
    for i in range(n):
        if s[i] != t[i]:
            a.append(i)
    if len(a) > 2 or len(a) == 1:
        print('NO')
    elif len(a) == 0:
        print('YES')
    elif s[a[0]] == s[a[1]] and t[a[0]] == t[a[1]]:
        print('YES')
    else:
        print('NO')