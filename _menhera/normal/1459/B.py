N = int(input())

if N % 2 == 0:
    ans = (1 + N / 2) * (1 + N / 2)
else:
    ans = ((N + 2) * (N + 2) - 1) / 2

print(str(ans).replace('.0', ''))