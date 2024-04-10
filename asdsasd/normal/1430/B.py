import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort(reverse = True)
    if k >= n - 1:
        print(sum(alst))
    else:
        print(sum(alst[:k + 1]))
    
    
for _ in range(int(input())):
    main()