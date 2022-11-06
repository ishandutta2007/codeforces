mod = 10 ** 9 + 7

x = input()[::-1]
n = len(x)

ans = 0

for i, t in enumerate(x):
    if t == '1':
        ans = (ans + pow(2, n - 1 + i)) % mod

print(ans)