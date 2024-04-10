import sys
input = sys.stdin.readline

def main():
    n, k, s = map(int, input().split())
    mi = k
    ma = (n - 1) * k
    if s < mi or ma < s:
        print("NO")
        return
    print("YES")
    pos = [1]
    for i in range(k, 0, -1):
        if (i - 1) + (n - 1) <= s:
            pos.append(n + 1 - pos[-1])
            s -= n - 1
        else:
            x = s - (i - 1)
            if pos[-1] > x:
                pos.append(pos[-1] - x)
            else:
                pos.append(pos[-1] + x)
            s -= x
        
    print(*pos[1:])
            
            
        
for _ in range(1):
    main()