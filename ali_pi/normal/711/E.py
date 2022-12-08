m = 10** 6 + 3
n, k = map(int, input().split())
p = 1
for i in range(n):
    p *= 2
    if p > k:
        break
if p < k:
    print('1 1')
    exit()
gcd = tmp = k - 1
while tmp:
    gcd -= tmp % 2
    tmp //= 2
b = pow(2, (k - 1) * n - gcd, m)
a = 1
mem = [-1]*100
for i in range(1, k):
    cnt = 0
    while i % 2 == 0:
        i //= 2
        cnt += 1
    if mem[cnt] == -1:
        mem[cnt] = pow(2, n - cnt, m)
    a = a * (mem[cnt] - i + m) % m
    if a == 0:
        break
print ((b - a + m) % m, b)