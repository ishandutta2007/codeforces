import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    a_s = []
    b_s = []
    ab_s = []
    for _ in range(n):
        t, a, b = map(int, input().split())
        if a == b == 1:
            ab_s.append(t)
        elif a == 1:
            a_s.append(t)
        elif b == 1:
            b_s.append(t)
    la = len(a_s)
    lb = len(b_s)
    lab = len(ab_s)
    if la + lab < k or lb + lab < k:
        print(-1)
        return
    a_s.sort()
    b_s.sort()
    for i in range(min(la, lb)):
        tmp = a_s[i] + b_s[i]
        ab_s.append(tmp)
    ab_s.sort()
    print(sum(ab_s[:k]))
        
        

main()
"""
for _ in range(int(input())):
    main()
"""