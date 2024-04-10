n = int(input())
a = list(map(int, input().split()))

i = 0
j = 0
ans = 0
while i < n:
    if j <= i:
        j = i+1
    while j < n and a[j] > a[j-1]:
        j += 1
    ans = max(j - i, ans)
    i += 1

print(ans)