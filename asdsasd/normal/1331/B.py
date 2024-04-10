import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = ""
    for i in range(2, n + 1):
        while n % i == 0:
            ans += str(i)
            n //= i
    print(ans)
    
main()