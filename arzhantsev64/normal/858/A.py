def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

n, k = list(map(int, input().split()))
print(n // gcd(n, 10**k) * 10 ** k)