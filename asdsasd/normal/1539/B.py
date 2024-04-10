import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    S = input().strip()
    cum = [0]
    for s in S:
        cum.append(cum[-1] + ord(s) - 96)
    for _ in range(q):
        l, r = map(int, input().split())
        print(cum[r] - cum[l - 1])
    
for _ in range(1):
    main()