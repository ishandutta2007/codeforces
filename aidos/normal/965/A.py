k, n, s, p = map(int, input().split())
ss = (n + s - 1)//s

print((k * ss + p - 1)//p)