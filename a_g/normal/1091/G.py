from random import randrange

def query(*args):
    print(*args)
    return int(input())

def gcd(m, n):
    if m < n:
        m, n = n, m
    if n == 0:
        return m
    return gcd(n, m%n)

N = int(input())
def factor(n):
    # check if prime
    is_prime = True
    for _ in range(3):
        k = randrange(2, n)
        if pow(k, n-1, n) != 1:
            is_prime = False
            break
    if is_prime:
        return [n]
    while True:
        k = randrange(1, n)
        ksq = k*k % N
        m = query("sqrt", ksq)
        for z in (-1, 1):
            g = gcd(abs(m+z*k), n)
            if g != 1 and g != n:
                return factor(g)+factor(n//g)


ans = factor(N)
print("!", len(ans), *ans)