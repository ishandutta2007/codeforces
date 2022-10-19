import sys
input = sys.stdin.readline

def main():
    x = int(input())
    if x > 45:
        print(-1)
        return
    ans = ""
    for i in range(9, 0, -1):
        if i >= x:
            ans += str(x)
            print(ans[::-1])
            return
        x -= i
        ans += str(i)
    
    
for _ in range(int(input())):
    main()