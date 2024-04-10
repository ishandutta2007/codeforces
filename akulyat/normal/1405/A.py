t = int(input())
while t:
    n = int(input())
    v = list(map(int, input().split()))
    v.reverse()
    for i in v:
        print(i, end=' ')
    print()
    t -= 1