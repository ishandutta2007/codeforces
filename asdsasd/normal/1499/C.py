import sys
input = sys.stdin.readline

def main():
    n = int(input())
    clst = list(map(int, input().split()))
    min_r = clst[0]
    min_u = clst[1]
    ans = min_r * n + min_u * n
    tmp = ans
    times = n - 2
    for i, c in enumerate(clst[2:]):
        if i % 2 == 0:
            tmp += c
            tmp -= min_r
            tmp -= (min_r - min(c, min_r)) * times
            min_r = min(min_r, c)
        else:
            tmp += c
            tmp -= min_u
            tmp -= (min_u - min(c, min_u)) * times
            times -= 1
            min_u = min(min_u, c)
        ans = min(ans, tmp)
    print(ans)
            
    
for _ in range(int(input())):
    main()