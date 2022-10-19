import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = list(input().strip())
    if "1" not in S:
        print("".join(S))
        return
    for _ in range(m):
        T = []
        flg = True
        for i in range(n):
            if S[i] == "1":
                T.append("1")
                continue
            T.append("0")
            cnt = 0
            if i != 0 and S[i - 1] == "1":
                cnt += 1
            if i != n - 1 and S[i + 1] == "1":
                cnt += 1
            if cnt == 1:
                T[-1] = "1"
                flg = False
        if flg:
            break
        S = T.copy()
    print("".join(T))
    
    
for _ in range(int(input())):
    main()