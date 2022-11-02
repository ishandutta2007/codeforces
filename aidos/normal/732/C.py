a = list(map(int, input().split()))
ans = 10 ** 22
for i in range(4):
    for j in range(4):
        b = a.copy()
        cnt = 0
        for k in range(i, 3):
            if b[k] > 0:
                b[k] -= 1 
            else:
                cnt += 1
        for k in range(j):
            if b[k] > 0:
                b[k] -= 1
            else:
                cnt += 1
        ans = min(ans, max(b) * 3 - sum(b) + cnt)
if max(a) == 1:
    i = 0
    while a[i] == 0:
        i += 1
    j = 2
    while a[j] == 0:
        j -= 1
    ans = min(ans, j - i + 1 - sum(a))
print(ans)