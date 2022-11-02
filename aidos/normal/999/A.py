n, k = map(int, input().split())
a = list(map(int, input().split()))

if max(a) <= k:
    print(n)
else:
    i = 0
    j = n-1
    while a[i] <= k:
        i += 1
    while a[j] <= k:
        j -= 1
    print(n - (j-i+1))