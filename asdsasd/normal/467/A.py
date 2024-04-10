import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = 0
    for _ in range(n):
        p, q = map(int, input().split())
        if p <= q - 2:
            ans += 1
    print(ans)
    
main()