import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    abc = "abc"
    ans = ""
    for i in range(n):
        ans += abc[i % 3]
    print(ans)
    
for _ in range(int(input())):
    main()