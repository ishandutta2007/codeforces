import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    if k > 2 ** (n - 1):
        print(-1)
        return
    
    if n == 1:
        print(1)
        return
    bi = bin(k - 1)[2:].zfill(n - 1)
    
    ans = []
    bef = 1
    for i, b in enumerate(bi, 1):
        if b == "0":
            for j in range(i, bef - 1, -1):
                ans.append(j)
            bef = i + 1
            
    for j in range(n, bef - 1, -1):
        ans.append(j)
    print(*ans)
    
for _ in range(int(input())):
    main()