import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if n % 2 == 0:
        ans = n // 2
    else:
        ans = n // 2 - n
    print(ans)
    
main()