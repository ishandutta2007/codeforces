import sys
input = sys.stdin.readline
    
def main():
    n = int(input())
    tizu = [list(input().strip()) for _ in range(n)]
    cnt = [0, 0, 0]
    for i in range(n):
        for j in range(n):
            if tizu[i][j] == "X":
                cnt[(i + j) % 3] += 1
    min_ = min(cnt)
    pos = cnt.index(min_)
    change = 0
    for i in range(n):
        for j in range(n):
            if tizu[i][j] == "X" and (i + j) % 3 == pos:
                tizu[i][j] = "O"
                change += 1
                
    #print("----", change)
    for row in tizu:
        print("".join(row))
    
for _ in range(int(input())):
    main()