

def isprime(p):
    if p <= 1: return False
    if p == 2: return True
    if p % 2 == 0: return False
    i = 3
    while i*i <= p:
        if p%i == 0: return False
        i += 2
    return True

for i in range(int(input())):
    d = int(input())
    
    p = d + 1
    while not isprime(p): p += 1
    
    q = p + d
    while not isprime(q): q += 1
    
    print(p*q)