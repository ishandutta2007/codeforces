import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    up = alst[0]
    down = 0
    for a in alst[1:]:
        if (up + down) == a:
            continue
        elif (up + down) < a:
            down = a - up
        else:
            up = a - down
        if up < 0 or down < 0:
            print("NO")
            return
    print("YES")
        
    
    
for _ in range(int(input())):
    main()