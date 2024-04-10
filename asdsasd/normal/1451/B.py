import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    S = input().strip()
    min_o = 10 ** 10
    min_l = 10 ** 10
    max_o = 0
    max_l = 0
    for i, s in enumerate(S, 1):
        if s == "0":
            min_o = min(min_o, i)
            max_o = max(max_o, i)
        else:
            min_l = min(min_l, i)
            max_l = max(max_l, i)
    for _ in range(q):
        l, r = map(int, input().split())
        if l in (min_o, min_l) and r in (max_o, max_l):
            print("NO")
        else:
            print("YES")
    
for _ in range(int(input())):
    main()