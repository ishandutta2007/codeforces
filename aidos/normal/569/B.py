n = int(input())
p = [-1] * n
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1
    if a[i] < n:
        p[a[i]] = i
j = 0
for i in range(n):
    if a[i] >= n or p[a[i]] != i:
        while p[j] != -1:
            j += 1
        p[j] = i
        a[i] = j
for i in a:
    print(i+1, end = ' ')