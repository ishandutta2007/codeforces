import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    if S == S[::-1]:
        print(0)
        return
    print(3)
    print("L", 2)
    print("R", 2)
    l = 2 * len(S) - 1
    print("R", l)
    
    
main()