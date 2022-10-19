import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = input().strip()
    alpha2num = {}
    t = 1
    for i in range(26):
        alp = chr(i + 97)
        alpha2num[alp] = t
        t *= 2
    cand = []
    total = alpha2num[S[-1]] - alpha2num[S[-2]]
    for s in S[:-2]:
        cand.append(alpha2num[s] * 2)
        total += alpha2num[s]
    
    total -= m
    cand.sort(reverse = True)
    for c in cand:
        if total >= c:
            total -= c
    if total == 0:
        print("Yes")
    else:
        print("No")
    
    
for _ in range(1):
    main()