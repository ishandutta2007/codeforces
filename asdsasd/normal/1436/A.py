import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    if sum(alst) == m:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()