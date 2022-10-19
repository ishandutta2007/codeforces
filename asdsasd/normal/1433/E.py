import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = 1
    for i in range(2, n):
        ans *= i
    
    print(ans // (n // 2))
    
    
main()