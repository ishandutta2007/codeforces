n, m, k = map(int, input().split())

if m > n+1:
    m = n+1
elif n > m + 1:
    n = m+1
print(n + m + 2 * k)