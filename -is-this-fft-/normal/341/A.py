from sys import stdin

def c2 (x):
    return x * (x - 1)

def gcd (p, q):
    if q == 0:
        return p
    return gcd(q, p % q)

n = int(stdin.readline())
arr = list(map(int, stdin.readline().split()))
arr.sort()

denom = n * (n - 1)
ans = 0
for i in range(n):
    L = i
    R = n - i - 1

    add = 0
    add += 2 * c2(L)
    add += 2 * L
    add += L
    add -= R
    add -= 2 * c2(R)

    ans += add * arr[i]

gc = gcd(ans, denom)
ans //= gc
denom //= gc
print(ans, denom)