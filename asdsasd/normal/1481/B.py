import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    hlst = list(map(int, input().split()))
    tot = 0
    max_ = 0
    for h in hlst[::-1]:
        tot += max(0, max_ - h)
        max_ = max(max_, h)
    if k > tot:
        print(-1)
        return
    for _ in range(k):
        for i in range(n):
            if hlst[i] >= hlst[i + 1]:
                continue
            else:
                hlst[i] += 1
                break
    print(i + 1)
    
for _ in range(int(input())):
    main()