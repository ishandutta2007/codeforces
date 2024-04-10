import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ab = []
    ans = 0
    for _ in range(n):
        a, b = map(int, input().split())
        ans += a
        ab.append((a, b))
    ab.sort(key = lambda x:-x[1])
    tot = ans
    ans *= 2
    for a, b in ab:
        if b >= tot:
            continue
        ans -= min(a, tot - b)
        tot -= min(a, tot - b)
    print(ans)
    
    
for _ in range(1):
    main()