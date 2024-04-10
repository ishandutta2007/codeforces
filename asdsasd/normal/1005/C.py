import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    se = set(A)
    bi = [1]
    for _ in range(30): bi.append(bi[-1] * 2)
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    
    ans = 0
    for a in A:
        cnt[a] -= 1
        if cnt[a] == 0:
            se.remove(a)
        for b in bi:
            if b - a in se:
                break
        else:
            ans += 1
        cnt[a] += 1
        if cnt[a] == 1:
            se.add(a)
    
    print(ans)
    
for _ in range(1):
    main()