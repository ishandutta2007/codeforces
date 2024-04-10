import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    x = alst[0]
    for a in alst:
        x &= a
    print(x)
    
for _ in range(int(input())):
    main()