import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = 0
    for a in A:
        cnt += a - 1
    if cnt % 2 == 0:
        print("maomao90")
    else:
        print("errorgorn")
    
for _ in range(int(input())):
    main()