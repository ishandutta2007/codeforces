import sys
input = sys.stdin.readline

def main():
    x, y = map(int, input().split())
    clst = list(map(int, input().split()))
    clst[0] = min(clst[0], clst[5] + clst[1])
    clst[1] = min(clst[1], clst[0] + clst[2])
    clst[2] = min(clst[2], clst[1] + clst[3])
    clst[3] = min(clst[3], clst[2] + clst[4])
    clst[4] = min(clst[4], clst[3] + clst[5])
    clst[5] = min(clst[5], clst[4] + clst[0])
    directions = [(1, 1), (0, 1), (-1, 0), (-1, -1), (0, -1), (1, 0)]
    ans = 10 ** 20
    for i in range(6):
        dx1, dy1 = directions[i]
        dx2, dy2 = directions[(i + 1) % 6]
        a = (x * dy2 - y * dx2) // (dx1 * dy2 - dy1 * dx2)
        b = (x * dy1 - y * dx1) // (dx2 * dy1 - dy2 * dx1)
        if a < 0 or b < 0:
            continue
        ans = min(ans, clst[i] * a + clst[(i + 1) % 6] * b)
    print(ans)
    
for _ in range(int(input())):
    main()