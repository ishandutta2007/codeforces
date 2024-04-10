a = input()

ans = 0
cnta = 0
mod=10**9 + 7
for i in a:
    if i == 'b':
        ans = (ans + cnta) % mod
    else:
        cnta = (cnta * 2 + 1) % mod
print(ans)