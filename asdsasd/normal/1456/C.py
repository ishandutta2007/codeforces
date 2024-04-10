import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort(reverse = True)
    pos = 0
    ans = 0
    total = 0
    while total >= 0 and pos < n:
        ans += total
        total += alst[pos]
        pos += 1
    alst = alst[pos:]
    alst.append(total)
    alst.sort()
    times = 0
    for i in range(0, len(alst), k + 1):
        for j in range(k + 1):
            if i + j >= len(alst):
                break
            ans += alst[i + j] * times
        times += 1

    
    print(ans)
    
    
for _ in range(1):
    main()