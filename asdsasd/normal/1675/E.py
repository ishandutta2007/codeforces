import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    S = input().strip()
    T = []
    flg = True
    ma = 0
    d = 0
    if k >= 25:
        print("a" * n)
        return
    for s in S:
        p = ord(s) - 97
        if flg:
            if p <= k:
                T.append("a")
                ma = max(ma, p)
            else:
                d = k - ma
                pp = p
                tm = p - d                
                T.append(chr(97 + tm))
                flg = False
        else:
            if p <= ma:
                T.append("a")
            elif p <= tm:
                T.append(chr(97 + p))
            elif p <= pp:
                T.append(chr(97 + tm))
            else:
                T.append(chr(97 + p))
    print(*T, sep="")

    

for _ in range(int(input())):
    main()