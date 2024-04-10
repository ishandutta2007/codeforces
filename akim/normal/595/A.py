
inp = list(map(int, input().split()))

n = inp[0]
m = inp[1]
ans = 0

for i in range(n):
    a = list(map(int, input().split()))
    for j in range(m):
        if a[j * 2] == 1 or a[j * 2 + 1] == 1:
            ans += 1
print(ans)

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));