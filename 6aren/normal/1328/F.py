[n, k] = map(int,input().split(' '))
a = list(map(int,input().split(' ')))
a.sort()
a.insert(0, 0)
a.append(0)
pref = [0] * (n + 2)
suff = [0] * (n + 2)

for i in range(1, n + 1):
    pref[i] = pref[i - 1] + a[i]
for i in range(n, 0, -1):
    suff[i] = suff[i + 1] + a[i]
ans = 1e18;
for i in range(1, n + 1):
    if (a[i] == a[i - 1]):
        continue
    l = i
    r = i
    while (a[r + 1] == a[l]):
        r = r + 1
    cur = r - l + 1
    if (cur >= k):
        ans = 0
        break
    need = k - cur
    if (need <= n - r):
        foo = suff[r + 1] - (a[i] + 1) * (n - r);
        foo += need;
        ans = min(ans, foo);
    if (need <= l - 1):
        foo = (l - 1) * (a[i] - 1) - pref[l - 1];
        foo += need;
        ans = min(ans, foo);
    foo = suff[r + 1] - (a[i] + 1) * (n - r) + (l - 1) * (a[i] - 1) - pref[l - 1];
    foo += need;
    ans = min(ans, foo);
print(ans)