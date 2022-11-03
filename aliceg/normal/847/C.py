from math import ceil

n, k = map(int, input().split())
if n * (n - 1) // 2 < k:
    print('Impossible')
    exit()

x = ceil(((8 * k + 1) ** 0.5 + 1) / 2)

p = x * (x - 1) // 2 - k

print('()' * (n - x) + '(' * (x - 1) + ')' * p + '()' + ')' * (x - p - 1))