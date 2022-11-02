n, b = map(int, input().split())
d = 10 ** 25
i = 2

while b != 1:
    if i * i > b:
        i = b
    if b % i == 0:
        cntb = 0
        cntn = 0
        nn = n
        while b % i == 0:
            b//=i
            cntb += 1
        while nn >= i:
            nn//=i
            cntn += nn
        d = min(d, cntn//cntb)
    i += 1

print(d)