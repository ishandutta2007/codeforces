import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    clst = list(map(int, input().split()))
    ans = 10 ** 20
    for i in range(1, 101):
        pos = 0
        sub = 0
        while pos < n:
            if clst[pos] != i:
                sub += 1
                pos += k
            else:
                pos += 1
        ans = min(ans, sub)
    print(ans)
    
for _ in range(int(input())):
    main()