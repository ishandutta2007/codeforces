n, x, y = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
    if min(a[max(i-x, 0):min(i+y+1, n)]) == a[i]:
        print(i+1)
        break