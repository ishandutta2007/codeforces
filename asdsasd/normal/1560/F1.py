import sys
input = sys.stdin.readline

bits = [[] for _ in range(11)]
for bit in range(1 << 10):
    se = set()
    for i in range(10):
        if bit >> i & 1:
            se.add(i)
    bits[len(se)].append(se)

def main():
    n, k = input().strip().split()
    k = int(k)
    l = len(n)
    times = (10 ** l - 1) // 9
    min_ = 10 ** 20
    for se in bits[k]:
        if max(se) * times < int(n):
            continue
        tmp = -1
        nex = [-1] * 10
        for i in range(9, -1, -1):
            if i in se:
                tmp = i
            nex[i] = tmp
        
        ans = []
        flg = False
        for i in range(l):
            if flg:
                ans.append(nex[0])
                continue
            s = int(n[i])
            t = nex[s]
            if t == s:
                ans.append(s)
            elif t != -1:
                ans.append(t)
                flg = True
            else:
                cnt = 1
                while 1:
                    s = ans[-1]
                    ans.pop()
                    if nex[s + 1] != -1:
                        ans.append(nex[s + 1])
                        break
                    cnt += 1
                for _ in range(cnt):
                    ans.append(nex[0])
                flg = True
        min_ = min(min_, int("".join(map(str, ans))))
    print(min_)
    
for _ in range(int(input())):
    main()