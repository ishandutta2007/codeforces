import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    edges = [-1] * n
    ans = 0
    for _ in range(m):
        x, y = map(int, input().split())
        if x != y:
            edges[y - 1] = x - 1
            ans += 1
    
    used = [False] * n
    for i in range(n):
        if used[i]:
            continue
        used[i] = True
        j = i
        while edges[j] != -1:
            j = edges[j]
            if j == i:
                ans += 1
                break
            used[j] = True
    print(ans)
    
    
    
for _ in range(int(input())):
    main()