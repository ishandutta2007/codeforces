inp = list(map(int, input().split()))

n = inp[0]
k = inp[1]
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cnt = 10 ** k
cnt1 = 10 ** (k - 1)
l = n // k
ans = 1

for i in range(l):
    c = ((cnt - 1) // a[i]) + 1
    c -= (((b[i] + 1) * cnt1 - 1) // a[i] + 1) - (((b[i] * cnt1 - 1) // a[i] + 1) if b[i] >= 0 else 0)
    ans *= c
    ans %= int(1e9 + 7)
print(ans)

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));