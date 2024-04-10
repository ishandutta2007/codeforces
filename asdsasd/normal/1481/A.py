import sys
input = sys.stdin.readline

def main():
    px, py = map(int, input().split())
    S = input().strip()
    if px >= 0:
        x = "R"
    else:
        x = "L"
        px *= -1
    if py >= 0:
        y = "U"
    else:
        y = "D"
        py *= -1
    for s in S:
        if s == x:
            px -= 1
        if s == y:
            py -= 1
    if px <= 0 and py <= 0:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()