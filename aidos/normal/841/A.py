n, k = map(int, input().split())
good = 1
a = sorted(input())
for i in range(k, n):
    if a[i] == a[i-k]:
        good = 0
print(['NO', 'YES'][good])