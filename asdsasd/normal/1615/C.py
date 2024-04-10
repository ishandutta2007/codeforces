import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = input().strip()
    B = input().strip()
    if A == B:
        print(0)
        return
    a0 = A.count("0")
    a1 = A.count("1")
    b0 = B.count("0")
    b1 = B.count("1")
    if b1 not in [a1, 1 + a0]:
        print(-1)
        return
    elif a1 == 0:
        print(-1)
        return
    cnt = [[0, 0], [0, 0]]
    for a, b in zip(A, B):
        cnt[int(a)][int(b)] += 1
    
    ans = 1 << 30

    if (cnt[0][0] + cnt[1][1]) % 2 == 1 and cnt[0][0] + 1 == cnt[1][1]:
        ans = min(ans, cnt[0][0] + cnt[1][1])

    if (cnt[0][1] + cnt[1][0]) % 2 == 0 and cnt[0][1] == cnt[1][0]:
        ans = min(ans, cnt[0][1] + cnt[1][0])
    
    
    if ans == 1 << 30:
        print(-1)
    else:
        print(ans)
    
        
    
    
    
for _ in range(int(input())):
    main()