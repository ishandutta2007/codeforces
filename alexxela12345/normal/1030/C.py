import sys
n = int(input())
arr = list(map(int, list(input())))
if n > 1 and sum(arr) == 0:
    print("YES")
    sys.exit(0)
arr = [el for el in arr if el != 0]
n = len(arr)
for i in range(1, sum(arr)):
    cur = 0
    cur_sum = 0
    while True:
        while cur < n and cur_sum < i:
            cur_sum += arr[cur]
            cur += 1
        if cur_sum == i:
            cur_sum = 0
        elif cur_sum != i:
            break
        if cur == n:
            print("YES")
            sys.exit(0)
print("NO")