import sys
input = sys.stdin.readline

def main():
    n = input().strip()
    n = int(n[-1])
    print(n % 2)
    
main()