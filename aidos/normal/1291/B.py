t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    i = 0
    while i < n and a[i] >= i:
        i += 1
    if i == n:
        print('Yes')
        continue
    i -= 1
    j = n-1
    while j >= 0 and a[j] >= n - j - 1:
        j -= 1
    if j < i:
        print('Yes')
    else:
        print('No')