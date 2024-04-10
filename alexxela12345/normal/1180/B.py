n = int(input())
arr = list(map(int, input().split()))
ans = 1
for i in range(n):
    if arr[i] >= 0:
        arr[i] = -arr[i] - 1
    ans *= 0 if arr[i] == 0 else arr[i] // abs(arr[i])
if ans < 0:
    min_ind = 0
    minn = arr[0]
    for i in range(1, n):
        if arr[i] < minn:
            minn = arr[i]
            min_ind = i
    arr[min_ind] = -arr[min_ind] - 1
print(*arr)