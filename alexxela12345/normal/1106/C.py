n = int(input())
arr = list(map(int, input().split()))
arr.sort()
i, j = 0, n - 1
ans = 0
if n % 2 == 1:
    ans += arr[-1] ** 2
    j = n - 2
while i <= j:
    if i < j:
        ans += (arr[i] + arr[j]) ** 2
        i += 1
        j -= 1
    else:
        print("lol")
print(ans)