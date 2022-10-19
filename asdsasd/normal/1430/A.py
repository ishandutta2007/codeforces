import sys
input = sys.stdin.readline

def main():
    n = int(input())
    for i in range(n // 3 + 1):
        for j in range(n // 5 + 1):
            for k in range(n // 7 + 1):
                if i * 3 + j * 5 + k * 7 == n:
                    print(i, j, k)
                    return
    print(-1)
    
for _ in range(int(input())):
    main()