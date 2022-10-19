import sys
inpu = sys.stdin.buffer.readline
prin = sys.stdout.write
from collections import defaultdict
for _ in range(int(inpu())) :
    n = int(inpu())
    a = list(map(int, inpu().split()))
    b = list(map(int, inpu().split()))
    stack = defaultdict(int)
    j = 0
    i = 0
    while j < n and i < n :
        if (a[i] == b[j]) and a[i] in stack and stack[a[i]] > 0:
            stack[a[i]] -= 1
            j += 1
        elif a[i] == b[j] :
            i += 1
            j += 1
        else :
            stack[a[i]] += 1
            i += 1
    for i in stack:
        if stack[i] > 0:
            prin("NO\n")
            break
    else:
        prin("YES\n")