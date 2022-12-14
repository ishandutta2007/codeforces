x, y = list(map(int, input().split()))
n = int(input())

s = (n - 1) % 6

if s == 0:
    print(x % 1000000007)
if s == 1:
    print(y % 1000000007)
if s == 2:
    print((y - x) % 1000000007)
if s == 3:
    print((-x) % 1000000007)
if s == 4:
    print((-y) % 1000000007)
if s == 5:
    print((x - y) % 1000000007)