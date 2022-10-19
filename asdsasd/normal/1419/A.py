import sys
input = sys.stdin.readline

def main():
    n = int(input())
    s = input().strip()
    if n % 2 == 0:
        flg = False
        for i in range(1, n, 2):
            if int(s[i]) % 2 == 0:
                flg = True
        if flg:
            print(2)
        else:
            print(1)
    else:
        flg = False
        for i in range(0, n, 2):
            if int(s[i]) % 2 == 1:
                flg = True
        if flg:
            print(1)
        else:
            print(2)
    
    
for _ in range(int(input())):
    main()