def f( a, b, c, d ):
    if (a==b and c==d) or (a==c and b==d) or (a==d and b==c): return 0
    if c==d or b==c or b==d or a==c or a==d: return 1
    return 2
n = input()
a, b, s = raw_input(), raw_input(), 0
for i in range(n//2):
    s += f(a[i], a[n-1-i], b[i], b[n-1-i])
if (n & 1) and a[n//2]!=b[n//2]: s += 1
print( s )