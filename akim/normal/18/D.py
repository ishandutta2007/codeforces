
dp = [0] * 5000;
v = [0] * 5000;

s2 = [0] * 5000;
s2[0] = 1;
for i in range(1, 5000, 1):
    s2[i] = s2[i - 1] + s2[i - 1];


n = int(input());
for i in range(0, n, 1):
    if(i - 1 >= 0):
        dp[i] = dp[i - 1];
    s, v[i] = input().split();
    v[i] = int(v[i]);
    if(s == "sell"):
        for j in reversed(range(0, i, 1)):
            if(v[j] == v[i]):
                dp[i] = max(dp[i], dp[j] + s2[v[i]]);
                break;
        v[i] = -1;
print(dp[n - 1]);

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000))