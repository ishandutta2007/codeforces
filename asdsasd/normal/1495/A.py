import sys
input = sys.stdin.readline

def main():
    n = int(input())
    miner = []
    dia = []
    for _ in range(2 * n):
        x, y = map(int, input().split())
        if y == 0: miner.append(abs(x))
        else: dia.append(abs(y))
    miner.sort()
    dia.sort()
    ans = 0
    for m, d in zip(miner, dia):
        ans += (m ** 2 + d ** 2) ** 0.5
    print(ans)
    
    
    
    
for _ in range(int(input())):
    main()