import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    if S[-1] == "A":
        print("NO")
        return
    tot = 0
    for s in S:
        if s == "A":
            tot += 1
        else:
            tot -= 1
            if tot < 0:
                print("NO")
                return
    print("YES")
        
    
for _ in range(int(input())):
    main()