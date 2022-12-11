
a = [0] * 100

m, n = list(map(int, input().split()))

ans = [0, 0]

for i in range(n):
    inp = list(map(int, input().split()))
    mx = [0, 0]
    for j in range(m):
        if inp[j] > mx[1]:
            mx = [j, inp[j]]
    a[mx[0]] += 1
    if ans[1] < a[mx[0]]:
        ans = [mx[0], a[mx[0]]]
    elif ans[1] == a[mx[0]] and ans[0] > mx[0]:
        ans = [mx[0], a[mx[0]]]
print(ans[0] + 1)

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim