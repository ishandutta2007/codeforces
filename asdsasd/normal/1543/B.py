import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    tot = sum(alst)
    x = tot % n
    y = n - x
    print(x * y)
    
for _ in range(int(input())):
    main()