n = int(input())
x = list(map(int, input().split()))
x.sort()

cnt = n - 2 - (n - 2) // 2
ans = int(1e9 + 7)
for i in range(cnt + 1):
    ans = min(ans, x[n - (cnt - i + 1)] - x[i])
print(ans)

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));