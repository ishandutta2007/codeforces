import sys
input = sys.stdin.readline


def main():
    n = int(input())
    alst = list(map(int, input().split()))
    for bit in range(1, 3 ** n):
        tot = 0
        for b in alst:
            if bit % 3 == 1:
                tot += b
            elif bit % 3 == 2:
                tot -= b
            bit //= 3
        
        if tot == 0:
            print("YES")
            return
        
    print("NO")
        
for _ in range(int(input())):
    main()