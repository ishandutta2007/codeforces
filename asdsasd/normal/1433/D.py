import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if max(alst) == min(alst):
        print("NO")
        return
    print("YES")
    max_ = max(alst)
    min_ = min(alst)
    max_pos = alst.index(max_) + 1
    min_pos = alst.index(min_) + 1
    ans = []
    for i, a in enumerate(alst):
        if a == max_:
            if i + 1 != max_pos:
                ans.append((min_pos, i + 1))
        else:
            ans.append((max_pos, i + 1))
    for row in ans:
        print(*row)
    
for _ in range(int(input())):
    main()