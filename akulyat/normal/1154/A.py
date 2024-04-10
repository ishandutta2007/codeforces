a, b, c, d=map(int, input().split())
for i in range(4):
    if (a>b):
        a,b=b,a
    if (b>c):
        b,c=c,b
    if (c>d):
        c,d=d,c
print(d-a, d-c, d-b, end=' ')