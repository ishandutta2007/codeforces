n = int(input())
a = list(map(int, input().split()))
b = a + a
i = 0
ans = 0
n *= 2
while i < n:
    if b[i] == 1:
        j = i
        while i < n and b[i] == 1:
            i += 1
        ans = max(i-j, ans)
    i += 1
print(ans)