md = 10 ** 9 + 7

def cnk(n, k):
    if k > n//2:
        k = n - k
    ans = 1
    for i in range(n-k+1, n+1):
        ans *= i
    for i in range(2, k+1):
        ans //= i
    ans = ans % md
    return ans


def factor(n):
    pws = []
    dv = 2
    lp = 0
    while n % dv == 0:
        lp += 1
        n //= dv
    if lp:
        pws.append(lp)
    dv = 3
    while n > 1 and dv * dv <= n:
        lp = 0
        while n % dv == 0:
            lp += 1
            n //= dv
        if lp:
            pws.append(lp)
        dv += 2
    if n > 1:
        pws.append(1)
    return pws


def main():
    q =input()
    for __ in range(q):
        x, y = raw_input().split()
        x, y = int(x), int(y)
        ans = pow(2, y - 1, md)
        for f in factor(x):
            cm = cnk(f + y - 1, y - 1)
            ans = (ans * cm) % md
        print(ans)


if __name__ == '__main__':
    main()