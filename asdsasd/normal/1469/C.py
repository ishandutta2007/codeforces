import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    H = list(map(int, input().split()))
    mi = ma = H[0]
    for h in H[1:]:
        mi -= k - 1
        ma += k - 1
        if mi > h + k - 1 or ma < h:
            print("NO")
            return
        mi = max(mi, h)
        ma = min(ma, h + k - 1)
    if mi == h:
        print("YES")
    else:
        print("NO")
        
    
for _ in range(int(input())):
    main()