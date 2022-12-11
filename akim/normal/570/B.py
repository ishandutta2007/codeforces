
n, m = list(map(int, input().split()))

if n - m > m - 1:
    print(min(m + 1, n))
else:
    print(max(m - 1, 1))

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim