def nice(d):
    for i in range (d-x, d+y+1):
        if i >= 0 and i < n and m[i] < m[d]:
            return False
    return True


n, x, y = map(int, input().split())
m = list(map(int, input().split()))

for i in range(n):
    if nice(i):
        print(i + 1)
        exit(0)