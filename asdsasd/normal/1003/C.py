import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    cum = [0]
    for a in A:
        cum.append(cum[-1] + a)
    max_ = 0
    for l in range(n):
        for r in range(l + k, n + 1):
            max_ = max(max_, (cum[r] - cum[l]) / (r - l))
    print(max_)
    
for _ in range(1):
    main()