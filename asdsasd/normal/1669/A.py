import sys
input = sys.stdin.readline

def main():
    n = int(input())
    print("Division ", end="")
    if n >= 1900:
        print(1)
    elif n >= 1600:
        print(2)
    elif n >= 1400:
        print(3)
    else:
        print(4)
    
    
for _ in range(int(input())):
    main()