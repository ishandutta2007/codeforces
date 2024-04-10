import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    if n < k:
        print("NO")
    elif k % 2 == 0 and n % 2 == 1:
        print("NO")
    elif n >= 2 * k:
        print("YES")
        if n % 2 == 0:
            ans = [2] * (k - 1) + [(n - 2 * (k - 1))]
            print(*ans)
        else:
            ans = [1] * (k - 1) + [(n - (k - 1))]
            print(*ans)
    else:
        if (n - (k - 1)) % 2 == 1:
            print("YES")
            ans = [1] * (k - 1) + [(n - (k - 1))]
            print(*ans)
        else:
            print("NO")
    
for _ in range(int(input())):
    main()