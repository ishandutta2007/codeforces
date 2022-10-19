import sys
input = sys.stdin.readline

def main():
    n, k1, k2 = map(int, input().split())
    w, b = map(int, input().split())
    w_can = min(k1, k2) + (abs(k1 - k2) // 2)
    k1 = n - k1
    k2 = n - k2
    b_can = min(k1, k2) + (abs(k1 - k2) // 2)
    if w <= w_can and b <= b_can:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()