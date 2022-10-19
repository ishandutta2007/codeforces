import sys
input = sys.stdin.buffer.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    one = alst.count(1)
    zero = alst.count(0)
    if zero * 2 >= n:
        print(zero)
        ans = [0] * zero
        print(*ans)
    elif one % 2 == 0:
        print(one)
        ans = [1] * one
        print(*ans)
    else:
        print(one - 1)
        ans = [1] * (one - 1)
        print(*ans)

    

for _ in range(int(input())):
    main()