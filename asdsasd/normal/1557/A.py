import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    max_a = max(alst)
    alst.remove(max_a)
    print(sum(alst) / (n - 1) + max_a)
    
for _ in range(int(input())):
    main()