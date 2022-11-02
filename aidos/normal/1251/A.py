t = int(input())
for _ in range(t):
    a = input()
    s = set()
    b = []
    for x in a:
        if len(b) == 0:
            b.append([1, x])
        elif b[-1][1] != x:
            b.append([1, x])
        else:
            b[-1][0] += 1
    for x in b:
        if x[0] % 2 == 1:
            s.add(x[1])
    print(''.join(sorted(s)))