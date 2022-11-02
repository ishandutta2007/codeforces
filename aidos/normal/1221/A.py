t = int(input())
for _ in range(t):
    n = int(input())
    s = 0
    a = map(int, input().split())
    for x in a:
        if x <= 2048:
            s += x
    if s >= 2048:
        print("YES")
    else:
        print("NO")