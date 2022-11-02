def gcd(a, b):
    if a==0:
        return (b, 0, 1)
    g, x1, y1 = gcd(b%a, a)
    x = y1 - (b // a) * x1
    y = x1
    return (g, x, y)
	
def solve(a, b, x, y, r):
    k = (r-x)//a
    y = (y-x) % b
    
    gg, X, Y = gcd(a, b)
    #print(gg, X, Y, y, a, b)
    if y % gg != 0:
        return 0
    X *= y // gg
    dd = b//gg
    if X >= 0:
        X -= (X//dd) * dd
    else:
        g = X//dd
        if g * dd > X:
            g += 1
        X -= g * dd
    
    if X < 0:
        X += dd
    elif X >= dd:
        X -= dd
    
    if X > k:
        return 0
    return (k-X)//dd + 1


a1, b1, a2, b2, L, R = map(int, input().split())
d1 = (L-b1)//a1
if d1 < 0:
    d1 = 0
d1 *= a1
d1 += b1
d2 = (L-b2)//a2
if d2 < 0:
    d2 = 0
d2 *= a2
d2 += b2

while d1 < L:
    d1 += a1
while d2 < L:
    d2 += a2

#print(d1, d2, L, R)

if R < max(d1, d2):
    print(0)
else:
    
    if d1 > d2 or (d1 == d2 and a1 < a2):
        print(solve(a1, a2, d1, d2, R))
    else:
        print(solve(a2, a1, d2, d1, R))