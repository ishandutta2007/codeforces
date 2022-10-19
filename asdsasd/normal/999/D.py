import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = [[] for _ in range(m)]
    for i, a in enumerate(A):
        cnt[a % m].append(i)
    ans = 0
    tot = []
    x = n // m
    for _ in range(2):
        for i in range(m):
            ans += len(tot)
            if len(cnt[i]) > x:
                for _ in range(len(cnt[i]) - x):
                    tot.append(cnt[i].pop())
            else:
                p = min(len(tot), x - len(cnt[i]))
                for _ in range(p):
                    cnt[i].append(tot.pop())
    
    print(ans)
    for i in range(m):
        for j in cnt[i]:
            p = i - (A[j] % m)
            A[j] += p % m
    print(*A)
    
    
for _ in range(1):
    main()