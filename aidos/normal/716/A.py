n, c = map(int, input().split())
a = list(map(int, input().split()))
n-=1
while n > 0:
    if a[n] - a[n-1] > c:
        break
    n -= 1
print(len(a) - n)