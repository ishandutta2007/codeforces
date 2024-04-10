n, m = map(int, input().split())
d = dict()
for i in range(n):
    a, b=input().split()
    d[b] = a
for i in range(m):
    a, b=input().split()
    print(a, b, '#' + d[b[:-1]])