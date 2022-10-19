import sys
input = sys.stdin.readline

def main():
    n = int(input())
    l = 0
    r = n
    plus = 0
    b = 0
    while r - l > 1:
        mid = (l + r) // 2
        print("+", (mid - plus) % n , flush=True)
        
        x = int(input())
        plus += (mid - plus) % n
        if x == b:
            l = mid
        else:
            r = mid
            b = x
    
    print("!", plus + n - r)
        
    
for _ in range(1):
    main()