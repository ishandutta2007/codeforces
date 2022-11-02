n = int(input())
s = input()
mod = 998244353
ans = 0
if s[0] == s[-1]:
    l = 0
    r = n-1
    while s[0] == s[l]:
        l += 1
    while s[n-1] == s[r]:
        r -= 1
    print(((l+1) * (n-r)) % mod)
else:
    l = 0
    while s[l] == s[0]:
        l += 1
    r = n-1
    while s[r] == s[n-1]:
        r -= 1
    print(l + n-r)