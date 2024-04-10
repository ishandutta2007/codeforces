import sys
input = sys.stdin.readline

def main():
    m = int(input())
    grid = [list(map(int, input().split())) for _ in range(2)]
    left = [0]
    for a in grid[1][:-1]:
        left.append(left[-1] + a)
    right = [0]
    for a in grid[0][1:][::-1]:
        right.append(right[-1] + a)
    ans = float("inf")
    
    for l, r in zip(left, right[::-1]):
        ans = min(ans, max(l, r))
    print(ans)
    
for _ in range(int(input())):
    main()