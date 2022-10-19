import sys
input = sys.stdin.readline

def main():
    n = int(input())
    
    odd = []
    even = []
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if (i + j) % 2 == 0:
                even.append((i, j))
            else:
                odd.append((i, j))
    
    for _ in range(n ** 2):
        c = int(input())
        if odd and even:
            if c in [1, 2]:
                x, y = odd.pop()
                print(3, x, y, flush = True)
            else:
                x, y = even.pop()
                print(1, x, y, flush = True)
        elif odd:
            x, y = odd.pop()
            if c in [1, 2]:
                print(3, x, y, flush = True)
            else:
                print(2, x, y, flush = True)
        else:
            x, y = even.pop()
            if c in [1, 3]:
                print(2, x, y, flush = True)
            else:
                print(1, x, y, flush = True)
    
    
    
    
    
for _ in range(1):
    main()