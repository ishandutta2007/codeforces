import sys
input = sys.stdin.readline

def main():
    a, b = map(int, input().split())
    if a == 0:
        print(1)
    else:
        print(a + 2 * b + 1)
    
    
for _ in range(int(input())):
    main()