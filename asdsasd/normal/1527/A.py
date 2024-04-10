import sys
input = sys.stdin.readline

def main():
    n = int(input())
    x = 1 << (n.bit_length() - 1)
    print(x - 1)
    
for _ in range(int(input())):
    main()