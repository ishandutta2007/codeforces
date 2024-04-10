import sys
input = sys.stdin.readline

def main():
    a, b, c, x, y = map(int, input().split())
    ok = True
    if x > a + c:
        ok = False
    if y > b + c:
        ok = False
    if x + y > a + b + c:
        ok = False
    if ok:
        print("YES")
    else:
        print("NO")
    
    
for _ in range(int(input())):
    main()