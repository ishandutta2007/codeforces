def gcd(a,b):
    #print(a,b)
    if b == 0:return a
    return gcd(b,a%b)
def kmm(a,b):
    return a*b//gcd(a,b)
a,b = map(int,input().split())
t = 0
while b > 0:
    divi=[]
    for i in range(1,int(a**0.5)+1):
        if a%i == 0:
            divi.append(i)
            divi.append(a//i)
    divi.pop(0)
    mods = []
    for i in divi:
        mods.append(b%i)
    m = min(mods)
    #km = 1
    t += m
    b -= m
    b2 = b
    b //= gcd(a,b)
    a //= gcd(a,b2)
    #print(a,b)
    if a == 1:
        t+=b
        break
print(t)