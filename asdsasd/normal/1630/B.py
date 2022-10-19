import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = A.copy()
    B.sort()
    min_ = 1 << 30
    z = (n + k + 1) // 2
    for i in range(n - z + 1):
        l = B[i]
        r = B[i + z - 1]
        if r - l < min_:
            min_ = r - l
            x, y = l, r
    
    print(x, y)
    ans = []
    l = 1
    tot = 0
    for i, a in enumerate(A, 1):
        if x <= a <= y:
            tot += 1
        else:
            tot -= 1
        if tot == 1:
            ans.append((l, i))
            l = i + 1
            tot = 0
    ans.append((l, n))
    while len(ans) > k:
        ans[-2] = (ans[-2][0], ans[-1][1])
        ans.pop()
    for row in ans:
        print(*row)
        
    
    
    
for _ in range(int(input())):
    main()