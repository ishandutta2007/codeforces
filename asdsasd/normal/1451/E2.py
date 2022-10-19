import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    inp = []
    for i in range(1, n):
        print("XOR", i, i + 1)
        sys.stdout.flush()
        tmp = int(input())
        inp.append(tmp)
    tmp = 0
    dd = defaultdict(int)
    dd[0] = 1
    flg = False
    for i, pp in enumerate(inp, 2):
        tmp ^= pp
        if dd[tmp] != 0:
            flg = True
            break
        dd[tmp] = i
    ans = [-1 for _ in range(n)]
    if flg:
        pos = dd[tmp]
        print("AND", pos, i)
        sys.stdout.flush()
        tmp = int(input())
        ans[pos - 1] = ans[i - 1] = tmp
        for j in range(pos - 2, -1, -1):
            ans[j] = inp[j] ^ ans[j + 1]
        for j in range(pos - 1, i - 2):
            ans[j + 1] = ans[j] ^ inp[j]
        for j in range(i - 1, n - 1):
            ans[j + 1] = ans[j] ^ inp[j]
        print("!", end = " ")
        print(*ans)
    else:
        print("AND", 1, dd[2])
        sys.stdout.flush()
        tmp = int(input())
        print("AND", 1, dd[1])
        sys.stdout.flush()
        if tmp % 2 == 0:
            ans[0] = int(input())
        else:
            ans[0] = int(input()) + 1
        for i, pp in enumerate(inp):
            ans[i + 1] = ans[i] ^ pp
        print("!", end = " ")
        print(*ans)

for _ in range(1):
    main()