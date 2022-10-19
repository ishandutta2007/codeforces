import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = [0] + list(map(int, input().split()))
    A.sort()
    if A[-1] >= A[-2] + 2:
        print("No")
    else:
        print("Yes")
    
    
for _ in range(int(input())):
    main()