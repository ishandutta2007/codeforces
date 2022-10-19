import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = [0] * 31
    for a in A:
        for i in range(31):
            if not a >> i & 1:
                cnt[i] += 1
    ans = 0
    for i in range(30, -1, -1):
        if cnt[i] <= k:
            k -= cnt[i]
            ans ^= 1 << i
    print(ans)
    
for _ in range(int(input())):
    main()