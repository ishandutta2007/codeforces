n, m = map(int, input().split())
b = [0]* m
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(1, len(a)):
        b[a[j] - 1] = 1
if sum(b) == m:
    print("YES")
else:
    print("NO")