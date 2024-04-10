n = int(input())
a = [0] * n
for i in range(n):
    x, a[i] = map(int, input().split())
i = 0
k = int(input())
while a[i] < k:
    i += 1
print(n-i)