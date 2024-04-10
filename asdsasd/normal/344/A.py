import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = 0
    bef = "00"
    for _ in range(n):
        a = input().strip()
        if bef != a:
            ans += 1
        bef = a
    print(ans)
    
main()