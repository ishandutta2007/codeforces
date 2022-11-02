n, m = map(int, input().split())
a = set(map(int, input().split()))
i = 1
cnt = 0
b = []
while i <= m:
    if i not in a:
        m -= i
        b.append(str(i))
        cnt += 1
    i += 1
print(cnt)
print(' '.join(b))