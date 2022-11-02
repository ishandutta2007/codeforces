n = int(input())
a = list(map(int, input().split()))

if a[n-1] == 15:
    print('DOWN')
elif a[n-1] == 0:
    print('UP')
elif n == 1:
    print(-1)
elif a[n-2] > a[n-1]:
    print('DOWN')
else:
    print('UP')