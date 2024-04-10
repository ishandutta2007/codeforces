import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    a = 0
    b = 0
    a_bef = 0
    b_bef = 0
    a_pos = 0
    b_pos = n - 1
    turn = 0
    flg = False
    while 1:
        tmp = 0
        if turn % 2 == 0:
            while 1:
                tmp += alst[a_pos]
                a_pos += 1
                if a_pos > b_pos:
                    flg = True
                    break
                if tmp > b_bef:
                    break
            a_bef = tmp
            a += tmp
        else:
            while 1:
                tmp += alst[b_pos]
                b_pos -= 1
                if a_pos > b_pos:
                    flg = True
                    break
                if tmp > a_bef:
                    break
            b_bef = tmp
            b += tmp
        turn += 1
        if flg:
            break
    print(turn, a, b)
            
    
for _ in range(int(input())):
    main()