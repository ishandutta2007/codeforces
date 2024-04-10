t = int(input())

for i in range(t):
    a, b, k = map(int, input().split())
    x = k//2
    print(a * (k - x) - b*x)