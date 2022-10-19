import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = [int(input()) for _ in range(n)]
    ans = []
    for a in alst:
        if a == 1:
            ans.append("1")
            print(".".join(ans))
            continue
        while ans and int(ans[-1]) != a - 1:
            ans.pop()
        if not ans:
            ans.append(str(a))
        else:
            ans.pop()
            ans.append(str(a))
        
        print(".".join(ans))
        
    
for _ in range(int(input())):
    main()