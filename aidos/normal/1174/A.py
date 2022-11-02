n = int(input())
a = sorted(map(int, input().split()))

if len(set(a)) == 1:
    print(-1)
else:
    for i in a:
        print(i, end = ' ')