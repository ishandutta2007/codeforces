n, k = map(int, input().split())

for i in range(n):
    if i < k:
        print(chr(ord('a') + i), end='')
    else:
        print(chr(ord('a') + (i-k) % 2), end='')