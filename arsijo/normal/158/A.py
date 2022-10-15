n, k = map(int, input().split())
array = list(map(int, input().split()))
ans = 0
for el in array:
    if el > 0 and el >= array[k - 1]:
        ans += 1
print(ans)