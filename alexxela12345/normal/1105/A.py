n = int(input())
arr = list(map(int, input().split()))
min_c = 1e9
tt = -1
for t in range(1, 101):
    new_arr = arr.copy()
    cost = 0
    for i in range(n):
        cost += min(abs(arr[i] - t + 1), abs(arr[i] - t), abs(arr[i] - t - 1))
    if cost < min_c:
        min_c = cost
        tt =  t
print(tt, min_c)