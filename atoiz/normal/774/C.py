n = int(input())
print(('7' if (n & 1) else '1') + (n // 2 - 1) * '1')