n = int(input())
j = 10
ans = 0
last = 0
while j - 1 < n:
    ans += len(str(j-1)) * (j-1-last)
    last = j-1
    j *= 10
ans += len(str(n)) * (n - last)
print(ans)