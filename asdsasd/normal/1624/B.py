import sys
input = sys.stdin.readline

def main():
    a, b, c = map(int, input().split())
    cc = 2 * b - a
    if cc > 0 and cc % c == 0:
        print("YES")
        return
    aa = 2 * b - c
    if aa > 0 and aa % a == 0:
        print("YES")
        return
    bb2 = a + c
    if bb2 % 2 == 0 and (bb2 // 2) % b == 0:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()