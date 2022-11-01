n,t = map(int,raw_input().split())
x = t
while len(str(x)) < n:
    x *= t

if len(str(x)) != n:
    print -1
else:
    print x