import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    n, m = map(int, input().split())
    l = len(S)
    zero_l = [-1] * l
    one_l = [-1] * l
    zero_r = [-1] * l
    one_r = [-1] * l
    que = []
    o = 0
    z = 0
    ans = 0
    for i, s in enumerate(S):
        zero_l[i] = z
        one_l[i] = o
        if s == "?":
            que.append(i)
        elif s == "0":
            z += 1
            ans += o * m
        else:
            o += 1
            ans += z * n
    o = 0
    z = 0
    for i, s in enumerate(S[::-1]):
        i = l - i - 1
        zero_r[i] = z
        one_r[i] = o
        
        if s == "0":
            z += 1
        elif s == "1":
            o += 1
    ll = len(que)
    z = [0] * ll
    for i, j in enumerate(que):
        z[i] = one_l[j] * m + one_r[j] * n
    o = [0] * ll
    for i, j in enumerate(que):
        o[i] = zero_l[j] * n + zero_r[j] * m
        
    zo_l = [0]
    for i in z:zo_l.append(zo_l[-1] + i)
    zo_r = [0]
    for i in o[::-1]:zo_r.append(zo_r[-1] + i)
    sub = float("inf")
    for i, (j, k) in enumerate(zip(zo_r, zo_l[::-1])):
        sub = min(sub, j + k + i * (ll - i) * n)
    
    oz_l = [0]
    for i in o:oz_l.append(oz_l[-1] + i)
    oz_r = [0]
    for i in z[::-1]:oz_r.append(oz_r[-1] + i)
    for i, (j, k) in enumerate(zip(oz_r, oz_l[::-1])):
        sub = min(sub, j + k + i * (ll - i) * m)
        
    print(ans + sub)
    
        
    
for _ in range(1):
    main()