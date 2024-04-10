import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = [list(input().strip()) for _ in range(n)]
    
    rev = {"1":"0", "0":"1"}
    ans = []
    for i in range(n - 2):
        for j in range(m - 2):
            if alst[i][j] == "1":
                alst[i][j] = "0"
                alst[i + 1][j] = rev[alst[i + 1][j]]
                alst[i][j + 1] = rev[alst[i][j + 1]]
                ans.append((i + 1, j + 1, i + 2, j + 1, i + 1, j + 2))
        
    i = n - 1
    for j in range(m - 2):
        if alst[i][j] == "1" and alst[i - 1][j] == "1":
            alst[i][j] = "0"
            alst[i - 1][j] = "0"
            alst[i][j + 1] = rev[alst[i][j + 1]]
            ans.append((i + 1, j + 1, i, j + 1, i + 1, j + 2))
        elif alst[i][j] == "1":
            alst[i][j] = "0"
            alst[i - 1][j + 1] = rev[alst[i - 1][j + 1]]
            alst[i][j + 1] = rev[alst[i][j + 1]]
            ans.append((i + 1, j + 1, i, j + 2, i + 1, j + 2))
        elif alst[i - 1][j] == "1":
            alst[i - 1][j] = "0"
            alst[i - 1][j + 1] = rev[alst[i - 1][j + 1]]
            alst[i][j + 1] = rev[alst[i][j + 1]]
            ans.append((i, j + 1, i, j + 2, i + 1, j + 2))
            
    j = m - 1
    for i in range(n - 2):
        if alst[i][j] == "1" and alst[i][j - 1] == "1":
            alst[i][j] = "0"
            alst[i][j - 1] = "0"
            alst[i + 1][j] = rev[alst[i + 1][j]]
            ans.append((i + 1, j + 1, i + 1, j, i + 2, j + 1))
        elif alst[i][j] == "1":
            alst[i][j] = "0"
            alst[i + 1][j - 1] = rev[alst[i + 1][j - 1]]
            alst[i + 1][j] = rev[alst[i + 1][j]]
            ans.append((i + 1, j + 1, i + 2, j, i + 2, j + 1))
        elif alst[i][j - 1] == "1":
            alst[i][j - 1] = "0"
            alst[i + 1][j - 1] = rev[alst[i + 1][j - 1]]
            alst[i + 1][j] = rev[alst[i + 1][j]]
            ans.append((i + 1, j, i + 2, j, i + 2, j + 1))
            
    blst = [alst[-2][-2:], alst[-1][-2:]]
    cnt = 0
    one = []
    for i in range(2):
        for j in range(2):
            if blst[i][j] == "1":
                one.append((i, j))
                cnt += 1
        
    lst = [(0, 0), (0, 1), (1, 0), (1, 1)]        
    
    if cnt == 0:
        pass
    if cnt == 4:
        one = [(1, 1)]
        tmp = []
        tmp.append(n - 1)
        tmp.append(m - 1)
        tmp.append(n)
        tmp.append(m - 1)
        tmp.append(n - 1)
        tmp.append(m)
        cnt = 1
        ans.append(tmp)
    if cnt == 1:
        tmp = [n - 1 + one[0][0], m - 1 + one[0][1]]
        sub = 1
        for l in lst:
            if l == one[0]:
                continue
            tmp.append(n - 1 + l[0])
            tmp.append(m - 1 + l[1])
            one.append(l)
            sub += 1
            if sub == 3:
                break
        ans.append(tmp)
        one = one[1:]
        cnt = 2
    if cnt == 2:
        tmp = [n - 1 + one[0][0], m - 1 + one[0][1]]
        for l in lst:
            if l in one:
                continue
            tmp.append(n - 1 + l[0])
            tmp.append(m - 1 + l[1])
            one.append(l)
        ans.append(tmp)
        one = one[1:]
        cnt = 3
    if cnt == 3:
        tmp = []
        for ii, jj in one:
            tmp.append(n - 1 + ii)
            tmp.append(m - 1 + jj)
        ans.append(tmp)
        cnt = 0
    
    
    print(len(ans))
    for row in ans:
        print(*row)
    
    
    
for _ in range(int(input())):
    main()