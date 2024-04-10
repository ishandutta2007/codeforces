import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = 0
    stair = 1
    while n > 0:
        ans += 1
        n -= stair * (stair + 1) // 2
        stair *= 2
        stair += 1
    if n != 0:
        ans -= 1
    print(ans)
    
for _ in range(int(input())):
    main()