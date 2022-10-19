import sys
input = sys.stdin.readline

def main():
    x = input().strip()
    n = int(x[0])
    l = len(x)
    ans = 10 * (n - 1) + l * (l + 1) // 2
    print(ans)
    
for _ in range(int(input())):
    main()