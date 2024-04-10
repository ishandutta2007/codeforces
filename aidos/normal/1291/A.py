t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = []
    for x in s:
        if (ord(x) - ord('0')) % 2 == 1:
            a.append(x)
    if len(a) > 1:
        print(''.join(a[:2]))
    else:
        print('-1')