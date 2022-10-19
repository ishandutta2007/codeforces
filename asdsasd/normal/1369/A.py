import sys
input = sys.stdin.readline

def main():
    if int(input()) % 4 == 0:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()