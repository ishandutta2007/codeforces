n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
arr = [0]
for i in range(1, n):
    arr.append(arr[-1] + a[i - 1])
cur = 0
for i in range(m):
    r = n
    l = cur
    while r - l > 1:
        mi = (r + l) // 2
        if b[i] > arr[mi]:
            l = mi
        else:
            r = mi
    cur = l
    print(cur + 1, b[i] - arr[cur])