import sys
input = sys.stdin.readline

def main():
    W, H = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split()) 
    w, h = map(int, input().split())
    w1 = x2 - x1
    h1 = y2 - y1
    if w1 + w > W and h1 + h > H:
        print(-1)
        return
    ans = float("inf")
    if w1 + w <= W:
        w1_l = x1
        w1_r = W - x2
        ans = min(ans, w - w1_l, w - w1_r)
    if h1 + h <= H:
        h1_l = y1
        h1_r = H - y2
        ans = min(ans, h - h1_l, h - h1_r)
    print(max(ans, 0))
    
    
for _ in range(int(input())):
    main()