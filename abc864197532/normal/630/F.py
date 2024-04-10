import math

def comb(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)

n = int(input())
print(comb(n, 5) + comb(n, 6) + comb(n, 7))