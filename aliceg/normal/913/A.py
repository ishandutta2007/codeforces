n = int(input())
m = int(input())
x = bin(m)
x = x[max(len(x) - n - 2, 0) + 2:]
s = 1
ans = 0
for i in range(len(x) -1, -1, -1):
    ans += int(x[i]) * s
    s = s << 1
print(ans)