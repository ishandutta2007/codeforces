s = map(lambda c: ord(c) - 48,raw_input())
r, t, f = 0, 0, 1
for x in s:
    if x < 0:
        r += f * t
        f = -4 - x
        t = 0
    t = t * 10 + x
print(r + f * t)