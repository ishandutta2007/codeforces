n, k = map(int, input().split())
d = 9 + 8 * k + 8 * n
print(n - (-3 + int(d ** 0.5 + 0.000001))//2)