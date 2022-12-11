
n, m = map(int, input().split())

s = [True] + [c != '.' for c in input()] + [True]
ans = sum(s[i] == s[i + 1] == 0 for i in range(1, n + 1))
inp = [0] * m
for i in range(m):
    inp[i] = input()
out = [0] * m
for i in range(m):
    pos, c = inp[i].split()
    pos, c = int(pos), c != '.' 
    if not s[pos]:
        if c: ans -= 2 - (s[pos - 1] + s[pos + 1])  
    else:
        if not c: ans += 2 - (s[pos - 1] + s[pos + 1])
    s[pos] = c
    out[i] = ans

print('\n'.join(map(str, out)))

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim