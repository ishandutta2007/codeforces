import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    l = -1
    r = n ^ (m + 1)
    while r - l > 1:
        mid = (r + l) // 2
        if n ^ mid <= m:
            l = mid
        else:
            r = mid
    print(r)
            
    
    
    
for _ in range(int(input())):
    main()