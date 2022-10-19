import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    if k == 1:
        if alst[0] == alst[-1]:
            print(1)
        else:
            print(-1)
        return
    cnt = 0
    bef = alst[0]
    for a in alst[1:]:
        if bef != a:
            cnt += 1
        bef = a
    k -= 1
    ans = (cnt + k - 1) // k
    print(max(ans, 1))
    
for _ in range(int(input())):
    main()