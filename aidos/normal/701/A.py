n = int(input())
a = list(map(int, input().split()))
b = []

for i in range(n):
    b.append([a[i], i + 1])

b = sorted(b)
for i in range(n//2):
    print(b[i][1], b[n-i-1][1])