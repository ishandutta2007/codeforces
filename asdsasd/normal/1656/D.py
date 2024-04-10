import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if bin(n).count("1") == 1:
        print(-1)
    elif n % 2 == 1:
        print(2)
    else:
        k = n
        while k % 2 == 0:
            k //= 2
        x = n - k * (k + 1) // 2
        if x >= 0 and x % k == 0:
            print(k)
        else:
            k = n & -n
            print(2 * k)
        
    
    
for _ in range(int(input())):
    main()