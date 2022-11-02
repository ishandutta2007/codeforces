t = int(input())
for i in range(t):
    l, r, d = map(int, input().split())
    if l > d:
        print(d)
    else:
        print(((r+d)//d) * d)