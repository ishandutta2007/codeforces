import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    lst = [1]
    bef = A[0]
    for i, a in enumerate(A, 1):
        if a != bef:
            lst.append(i)
            bef = a
    lst.append(n + 1)
    l = len(lst)
    for i in range(l - 1):
        if lst[i + 1] == lst[i] + 1:
            print(-1)
            return
    ans = []
    for i in range(l - 1):
        tmp = list(range(lst[i], lst[i + 1]))
        tmp = tmp[1:] + tmp[:1]
        ans += tmp
    print(*ans)
    
    
for _ in range(int(input())):
    solve()