t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    if (sum(a) + 1)//2 >= max(a):
        print('Yes')
    else:
        print('No')