import sys
input = sys.stdin.readline
MOD = 998244353

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    ans = 1
    dic = {}
    for i, a in enumerate(alst, 1):
        dic[a] = i
    for i in range(k):
        blst[i] = dic[blst[i]] - 1
    
    tf = [True for _ in range(n)]
    ans = 1
    for b in blst[::-1]:
        if b == 0:
            if not tf[1]:
                print(0)
                return
        elif b == n - 1:
            if not tf[n - 2]:
                print(0)
                return
        else:
            cnt = int(tf[b + 1]) + int(tf[b - 1])
            if cnt == 2:
                ans *= 2
                ans %= MOD
            elif cnt == 0:
                print(0)
                return
        tf[b] = False
    print(ans)
for _ in range(int(input())):
    main()