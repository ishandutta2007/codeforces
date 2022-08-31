cnt = [1, 1, 2, 7, 4]
arr = list(map(int, input().split(" ")))
 
for i in range(5):
    arr[i] //= cnt[i]
 
print(min(arr))