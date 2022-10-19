import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    ma = len(S)
    S = S.split()
    T = []
    se = set(S)
    lst = sorted(se)
    dic = {l:chr(i) for i, l in enumerate(lst)}
    length = {chr(i):len(l) for i, l in enumerate(lst)}
    for s in S:
        T.append(dic[s])
        
    T = "".join(T)
    ans = ma
    for i in range(n):
        for j in range(i + 1, n + 1):
            if j + j - i > n:
                break
            t = T.count(T[i:j])
            if t >= 2:
                minus = j - i - 1
                for k in range(i, j):
                    minus += length[T[k]] - 1
                ans = min(ans, ma - minus * t)
    print(ans)
    
for _ in range(1):
    main()