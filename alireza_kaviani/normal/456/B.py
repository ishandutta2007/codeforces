n = int(input())
print((1 + 2 ** (n % 4) + 3 ** (n % 4) + 4 ** (n % 2)) % 5)