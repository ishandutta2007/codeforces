import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    S = input().strip()
    cum = [0]
    for i, s in enumerate(S):
        if (s == "+") ^ (i % 2 == 0):
            cum.append(cum[-1] + 1)
        else:
            cum.append(cum[-1] - 1)
    for _ in range(q):
        l, r = map(int, input().split())
        d = cum[r] - cum[l - 1]
        if d == 0:
            print(0)
        elif d % 2 == 1:
            print(1)
        else:
            print(2)
    
for _ in range(int(input())):
    main()