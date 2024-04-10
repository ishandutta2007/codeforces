import sys
input = sys.stdin.readline

def f(x):
    ret = 0
    while x % 3 == 0:
        x //= 3
        ret += 1
    return ret

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort(key = lambda x:(-f(x), x))
    print(*A)
    
    
for _ in range(1):
    main()