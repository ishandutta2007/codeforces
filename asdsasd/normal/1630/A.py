import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    if k == n - 1:
        if n == 4:
            print(-1)
        else:
            ans = [[i, n - 1 - i] for i in range(n // 2)]
            ans[0][1], ans[1][0] = ans[1][0], ans[0][1]
            ans[-1][1], ans[-2][1] = ans[-2][1], ans[-1][1]
            tot = 0
            for a, b in ans:
                print(a, b)
                tot += a & b
            assert tot == k
                
        return
    
    ans = [(i, n - 1 - i) for i in range(n // 2)]
    x = (n - 1) ^ k
    x = x & -x
    y = k ^ x
    tot = 0
    se = set()
    for a, b in ans:
        if a in [x, y]:
            a ^= x ^ y
        if b in [x, y]:
            b ^= x ^ y
        print(a, b)
        tot += a & b
        se |= {a, b}

    assert tot == k
    assert len(se) == n
    
for _ in range(int(input())):
    main()