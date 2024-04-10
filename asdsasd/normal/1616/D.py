import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    x = int(input())
    for i in range(n):
        A[i] -= x
    tot = 0
    inf = 1 << 30
    max_ = -inf
    ans = n
    
    for a in A:
        tmp = a + tot
        if tmp < max_:
            ans -= 1
            max_ = -inf
            tot = 0
        else:
            max_ = max(max_, tot)
            tot = tmp
    print(ans)
    
for _ in range(int(input())):
    main()