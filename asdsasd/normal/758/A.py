import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    max_ = max(alst)
    print(max_ * n - sum(alst))
    
main()
"""
for _ in range(int(input())):
    main()
"""