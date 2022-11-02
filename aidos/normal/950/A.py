l, r, a = map(int, input().split())
d = min(abs(r-l), a)
a -= d
print((min(l, r) + d + a//2)*2)