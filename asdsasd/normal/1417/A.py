import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort()
    min_ = alst[0]
    ans = 0
    for a in alst[1:]:
        num = k - a
        ans += num // min_
    print(ans)
    
    
    
for _ in range(int(input())):
    main()