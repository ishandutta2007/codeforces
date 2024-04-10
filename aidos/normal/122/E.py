import math

def good(x):
    while x > 0:
        if x % 10 != 4 and x % 10 != 7:
            return False
        x //=10
    return True

n, k = map(int, input().split())

l = 1
r = n
if n >= 15:
    l = n-14
if n <= 15 and math.factorial(n) < k:
    print(-1)
else:
    L = r - l + 1
    a = []
    for i in range(L):
        a.append(i)
    b = []
    k -= 1
    for i in range(L):
        x = k//math.factorial(L-i-1)
        y = a[x]
        b.append(y+l)
        a.remove(y)
        k -= x * math.factorial(L-i-1)
    c = []
    if 4 < l:
        c.append(4)
    if 7 < l:
        c.append(7)
    ans = 0
    while len(c) > 0:
        ans += len(c)
        cc = []
        for x in c:
            if x * 10 + 4 < l:
                cc.append(x * 10 + 4)
            if x * 10 + 7 < l:
                cc.append(x * 10 + 7)
        c = cc
    for i in range(L):
        if good(i+l) and good(b[i]):
            ans += 1
    print(ans)