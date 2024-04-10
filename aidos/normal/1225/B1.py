t = int(input())
for _ in range(t):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    s = dict()
    ans = n
    for i in range(n):
        s[a[i]] = s.get(a[i], 0) + 1
        if i >= d:
            s[a[i-d]] -= 1
            if s[a[i-d]] == 0:
                s.pop(a[i-d])
        if i >= d-1:
            ans = min(ans, len(s))
    print(ans)