n = int(input())
a = [0] * 3
b = [0] * n
for i in range(3):
    a[i] = list(map(int, input().split()))

b[0] = int((a[0][1] * a[0][2]//a[1][2]) ** 0.5 + 0.000001)

for i in range(1, n):
    b[i] = a[0][i]//b[0]
print(' '.join(map(str, b)))