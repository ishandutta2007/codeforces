import sys
input = sys.stdin.readline

def main():
    n = int(input())
    blst = list(map(int, input().split()))
    blst.sort()
    bef = -1
    for b in blst:
        if b == bef:
            print("YES")
            return
        bef = b
    print("NO")
    
for _ in range(int(input())):
    main()