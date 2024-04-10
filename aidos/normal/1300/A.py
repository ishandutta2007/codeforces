t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if 0 in a:
        x = a.count(0)
        if sum(a) + x == 0:
            x += 1
        print(x)
    elif sum(a) == 0:
        print(1)
    else:
        print(0)