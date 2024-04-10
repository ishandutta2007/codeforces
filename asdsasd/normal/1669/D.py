import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip().split("W")
    for s in S:
        b = 0
        r = 0
        for t in s:
            if t == "B":
                b += 1
            elif t == "R":
                r += 1
        if b == 0 and r == 0:
            continue
        elif b == 0 or r == 0:
            print("NO")
            return
    
    print("YES")
    
    
for _ in range(int(input())):
    main()