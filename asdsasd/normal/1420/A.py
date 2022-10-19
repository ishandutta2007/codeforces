import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    bef = alst[0]
    for a in alst[1:]:
        if a >= bef:
            print("YES")
            return
        bef = a
    print("NO")
    
for _ in range(int(input())):
    main()