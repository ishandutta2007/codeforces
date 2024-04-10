n = int(input())
is_prime = [True for _ in range(n)]
for i in range(2, int(n ** 0.5 + 1)):
    if not is_prime[i]:
        continue
    for j in range(i ** 2, n, i):
        is_prime[j] = False

for i in range(4, n, 2):
    if not is_prime[n - i]:
        print(i, n - i)
        break