from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    dd = defaultdict(int)
    for _ in range(n):
        s = input()
        for ss in s:
            dd[ss] += 1
    flg = False
    for _, num in dd.items():
        if num % n != 0:
            flg = True
            break
    if flg:
        print("NO")
    else:
        print("YES")