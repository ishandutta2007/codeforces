n, a, b = map(int, raw_input().split())
pw = 2**a
p = [map(int, raw_input().split()) for _ in range(n)]
p1 = filter(lambda x: x[1] > x[0], p)
p2 = filter(lambda x: x[1] <= x[0], p)
p2 = sorted(p2, key=lambda x: x[0] - x[1])
if b != 0:
    p_21 = p2[:-b]
    p_22 = p2[-b:]
else:
    p_21 = p2
    p_22 = []
ans = 0
ans += sum(map(lambda x: x[1], p1))
ans += sum(map(lambda x: x[1], p_21))
ans += sum(map(lambda x: x[0], p_22))
if b != 0:
    ans2 = ans
    for x, y in p_22:
        t = ans - x + x*pw
        if t>ans2:
            ans2 = t
    #print (p_22)
    if len(p_22) - b >= 0 and len(p_22) > 0:
        ans = ans - p_22[0][0] + p_22[0][1]
    for x, y in p_21:
        t = ans - y + x*pw
        if t>ans2:
            ans2 = t
    for x, y in p1:
        t = ans - y + x*pw
        if t>ans2:
            ans2 = t
    ans = ans2
print ans