a, b, c = input().split()
a = int(a)
if c == 'week':
    z = 4
    a -= 1
    ans = 0
    for i in range(366):
        if a == z:
            ans += 1
        z = (z + 1) % 7
    print(ans)
else:
    if a == 31:
        print(7)
    elif a == 30:
        print(11)
    else:
        print(12)