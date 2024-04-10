n = int(input())
c = list(map(int,input().split()))
a, b = 0, 0
last = ''
for i in range(n):
    x = input()
    if i == 0:
        a = 0
        b = c[i]
    else:
        aa, bb = 10 ** 15, 10 ** 15
        if x >= last:
            aa = min(aa, a)
        if x >= last[::-1]:
            aa = min(aa, b)
        if x[::-1] >= last:
            bb = min(bb, a + c[i])
        if x[::-1] >= last[::-1]:
            bb = min(bb, b + c[i])
        a, b = aa, bb
    last = x

if min(a, b) > sum(c):
    print(-1)
else:
    print(min(a, b))