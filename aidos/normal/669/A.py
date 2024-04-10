n = int(input())

k = n//3
ans= k * 2
n %= 3
if n > 0:
    ans += 1
print(ans)