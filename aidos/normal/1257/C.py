t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = dict()
    ans = n + 1
    for i in range(n):
        if a[i] in s:
            ans = min(i - s.get(a[i])+1, ans)
        s[a[i]] = i
    if ans > n:
        ans = -1
    print(ans)