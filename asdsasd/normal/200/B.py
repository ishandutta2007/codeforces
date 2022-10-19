import sys
input = sys.stdin.readline

def main():
    n = int(input())
    plst = list(map(int, input().split()))
    print(sum(plst) / n)
    
main()