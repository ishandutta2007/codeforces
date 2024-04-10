import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input()
    if "0" not in S:
        d = n // 2 * 2
        print(1, d, 1, d // 2)
        return
    ind = S.index("0") + 1
    if ind <= (n + 1) // 2:
        print(ind, n, ind + 1, n)
    else:
        print(1, ind, 1, ind - 1)
    
    
for _ in range(int(input())):
    main()