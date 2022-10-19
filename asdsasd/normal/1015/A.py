import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    imos = [0] * (m + 1)
    for _ in range(n):
        l, r = map(int, input().split())
        imos[l - 1] += 1
        imos[r] -= 1
    ans = []
    for i in range(m):
        imos[i + 1] += imos[i]
        if imos[i] == 0:
            ans.append(i + 1)
    print(len(ans))
    print(*ans)
    
for _ in range(1):
    main()