n = int(input())
a = list(map(int, input().split()))
b = [0] * (2**20)
c = [0] * (2**20)
b[0] += 1
s = 0
ans = 0
for i in range(n):
    s ^= a[i]
    if i % 2 == 0:
        ans += c[s]
        c[s] += 1
    else:
        ans += b[s]
        b[s] += 1
print(ans)