n = int(input())
a = list(map(int, input().split()))
s = int(0);
a.sort()
for i in range(len(a)):
    s += a[i]
if s & 1:
    for i in range(len(a)):
        if a[i] & 1:
            s -= a[i]
            break
    
print(s)
    
import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim