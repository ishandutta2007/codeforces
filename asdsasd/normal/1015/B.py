import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = list(input().strip())
    T = list(input().strip())
    if sorted(S) != sorted(T):
        print(-1)
        return
    
    ans = []
    for i in range(n):
        for j in range(i, n):
            if T[i] == S[j]:
                for k in range(j - 1, i - 1, -1):
                    ans.append(k + 1)
                    S[k], S[k + 1] = S[k + 1], S[k]
                break
    print(len(ans))
    print(*ans)
    
for _ in range(1):
    main()