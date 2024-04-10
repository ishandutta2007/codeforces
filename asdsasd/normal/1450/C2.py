import sys
input = sys.stdin.readline
    
def main():
    n = int(input())
    tizu = [list(input().strip()) for _ in range(n)]
    cnt_o = [0, 0, 0]
    cnt_x = [0, 0, 0]
    for i in range(n):
        for j in range(n):
            if tizu[i][j] == "X":
                cnt_x[(i + j) % 3] += 1
            elif tizu[i][j] == "O":
                cnt_o[(i + j) % 3] += 1
    
    total = sum(cnt_o) + sum(cnt_x)
    for o_ind, oo in enumerate(cnt_o):
        for x_ind, xx in enumerate(cnt_x):
            if o_ind == x_ind:
                continue
            if (oo + xx) * 3 <= total:
                break
        else:
            continue
        break
    
    change = 0
    for i in range(n):
        for j in range(n):
            if (i + j) % 3 == o_ind and tizu[i][j] == "O":
                tizu[i][j] = "X"
                change += 1
            elif (i + j) % 3 == x_ind and tizu[i][j] == "X":
                tizu[i][j] = "O"
                change += 1
                
    #print("----", change, sum(cnt_x) + sum(cnt_o))
    for row in tizu:
        print("".join(row))
    
for _ in range(int(input())):
    main()