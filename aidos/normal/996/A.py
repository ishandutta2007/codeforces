a = [100, 20, 10, 5, 1]
ans = 0
n = int(input())

for x in a:
    ans += n//x
    n %= x
print(ans)