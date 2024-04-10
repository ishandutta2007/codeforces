n, s = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()
m = n // 2
cnt = abs(arr[m] - s)
arr[m] = s
for i in range(m - 1, -1, -1):
    if arr[i] > s:
        cnt += arr[i] - s
        arr[i] = s
for i in range(m + 1, n, 1):
    if arr[i] < s:
        cnt += s - arr[i]
        arr[i] = s
print(cnt)