n = int(input())
a = list(map(int, input().split()))
for i in range(n-2, -1, -1):
    a[i] = max(min(a[i+1] - 1, a[i]), 0)
print(sum(a))