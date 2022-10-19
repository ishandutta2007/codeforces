import sys
input = sys.stdin.readline

def t1(k, x):
    if x % 100000 == 0:
        return k + x // 100000
    else:
        return k + x // 100000 + 1

def t2(k, x):
    ret = k * x
    if ret % 100000 == 0:
        return ret // 100000
    else:
        return ret // 100000 + 1

def main():
    n, m = map(int, input().split())
    ans = [-1] * (m + 1)
    ans[0] = 0
    for i in range(1, n + 1):
        t, x, y = map(int, input().split())
        tf = [False] * (m + 1)
        if t == 1:
            for j in range(m + 1):
                if tf[j] or ans[j] == -1:
                    continue
                cnt = y
                k = j
                while cnt > 0:
                    cnt -= 1
                    k = t1(k, x)
                    if k > m:
                        break
                    tf[k] = True
                    if ans[k] == -1:
                        ans[k] = i
                    else:
                        cnt = y
        else:
            for j in range(m + 1):
                if j == 0:
                    continue
                if tf[j] or ans[j] == -1:
                    continue
                cnt = y
                k = j
                while cnt > 0:
                    cnt -= 1
                    k = t2(k, x)
                    if k > m:
                        break
                    tf[k] = True
                    if ans[k] == -1:
                        ans[k] = i
                    else:
                        cnt = y
        
    print(*ans[1:])
        
    
    
    
for _ in range(1):
    main()