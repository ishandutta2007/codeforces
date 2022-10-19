import sys
input = sys.stdin.readline

def main():
    n = int(input())
    money_s = [100, 20, 10, 5, 1]
    ans = 0
    for m in money_s:
        ans += n // m
        n %= m
    print(ans)
    
main()