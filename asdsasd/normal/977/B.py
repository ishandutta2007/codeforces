import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    cnt = {}
    for i in range(n - 1):
        s = S[i:i+2]
        cnt[s] = cnt.get(s, 0) + 1
    max_ = max(cnt.values())
    for k, v in cnt.items():
        if v == max_:
            print(k)
            return
    
    
for _ in range(1):
    main()