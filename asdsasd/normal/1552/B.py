import sys
input = sys.stdin.readline

def main():
    n = int(input())
    R = [list(map(int, input().split())) for _ in range(n)]
    i = 0
    for j in range(1, n):
        cnt = 0
        for k in range(5):
            if R[i][k] < R[j][k]:
                cnt += 1
        if cnt <= 2:
            i = j
    flg = True
    for j in range(n):
        cnt = 0
        if i == j:
            continue
        for k in range(5):
            if R[i][k] < R[j][k]:
                cnt += 1
        if cnt <= 2:
            flg = False
            break
    if flg:
        print(i + 1)
        return
    print(-1)
        
    
for _ in range(int(input())):
    main()