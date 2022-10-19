import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    for a in A:
        cnt[a] = max(cnt.get(a, 0), cnt.get(a - 1, 0) + 1)
    max_ = 0
    k = -1
    for key, value in cnt.items():
        if value > max_:
            max_ = value
            k = key
    print(max_)
    ans = []
    for i in range(n - 1, -1, -1):
        if A[i] == k:
            ans.append(i + 1)
            k -= 1
    print(*ans[::-1])
    
    
    
    
    
for _ in range(1):
    main()