n, k = map(int, input().split())
a = input()
A = 0
for i in range(n):
    A += int(a[i])
s=0
c=0
W=False
L=False
D=False
for i in range(n):
    s += int(a[i])
    if i >= k:
        s -= int(a[i-k])
        c += int(a[i-k])
    if i >= k-1:
        if s == A:
            W = True
        elif  A - s + k == n:
            W = True
        elif c > 0 and A - s - c>0:
            D = True
        elif c == 0 and i >= k and i < n-1 and c == 0 and A -s -c == 0:
            D = True
if W:
    print('tokitsukaze')
elif D or k * 2 < n:
    print('once again')
else:
    print('quailty')