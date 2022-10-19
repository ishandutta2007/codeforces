import sys
input = sys.stdin.readline

def main():
    n = int(input())
    xlst = list(map(int, input().split()))
    se = set()
    for i in range(n):
        for j in range(i + 1, n):
            se.add(xlst[j] - xlst[i])
    print(len(se))
    
    
for _ in range(int(input())):
    main()