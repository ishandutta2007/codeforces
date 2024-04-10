n = int(raw_input())
a = map(int, raw_input().split())
c = map(int, raw_input().split())
ans = [0] * len(c)
s = 0;
for x in a:
    s += x
    for j in reversed(range(len(c))):
        ans[j] += s / c[j]
        s %= c[j]
print ' '.join(map(str, ans))
print s