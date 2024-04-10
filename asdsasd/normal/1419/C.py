import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    alst = list(map(int, input().split()))
    if alst.count(x) == n:
        print(0)
    elif sum(alst) == x * n:
        print(1)
    elif x in alst:
        print(1)
    else:
        print(2)
    
    
for _ in range(int(input())):
    main()