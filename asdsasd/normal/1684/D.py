import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    if n == k:
        print(0)
        return
    B = [(a + i, i) for i, a in enumerate(A)]
    B.sort(reverse = True)
    jump = [False] * n
    for _, i in B[:k]:
        jump[i] = True
    cnt = 0
    ans = 0
    for i, a in enumerate(A):
        if jump[i]:
            cnt += 1
        else:
            ans += a + cnt
    print(ans)
    
for _ in range(int(input())):
    solve()