n = int(input())
a = list(map(int, input().split()))
b = [1] * 110
j = 0
ans = 0
for i in range(len(a)):
    if a[i] == 1:
        j += 1
        ans = 1
    else:
        b[j] += 1
for i in range(1, j):
    ans *= b[i]
print(ans);

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim