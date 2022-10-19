import sys
input = sys.stdin.readline

def main():
    abc = list(map(int, input().split()))
    print(max(abc))
    
for _ in range(int(input())):
    main()