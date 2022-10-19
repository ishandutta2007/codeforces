import sys
input = sys.stdin.readline



def main():
    n, k = map(int, input().split())
    d = n // 200 + 1
    pos = 1
    up = -1
    down = -1
    while 1:
        print("?", pos)
        sys.stdout.flush()
        x = int(input())
        if x > k:
            up = pos
        elif x < k:
            down = pos
        pos += d
        pos = (pos - 1) % n + 1
            
        if up != -1 and down != -1:
            break
    
    if up < down:
        up += n
    while 1:
        mid = (up + down) // 2
        tmp = (mid - 1) % n + 1
        print("?", tmp)
        sys.stdout.flush()
        x = int(input())
        if x == k:
            print("!", tmp)
            return
        elif x > k:
            up = mid
        else:
            down = mid
        
        
for _ in range(1):
    main()