import sys
input = sys.stdin.readline

def main():
    n, h = map(int, input().split())
    alst = list(map(int, input().split()))
    ans = 0
    for a in alst:
        if a > h:
            ans += 2
        else:
            ans += 1
    print(ans)
    
main()