n = int(input())
a = sorted(map(int, input().split()))
x = (n-1)//2
if a[x] < 0:
    print(-1)
elif a[n-1-x] > 0:
    print(1)
else:
    print(0)