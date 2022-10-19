import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    se = set(alst)
    lst = sorted(se)
    dic = {}
    for i, a in enumerate(lst):
        dic[a] = i
    alst = [dic[a] for a in alst]
    bef = -10
    cnt = 0
    for a in alst:
        if bef + 1 != a:
            cnt += 1
        bef = a
    if cnt <= k:
        print("Yes")
    else:
        print("No")
    
for _ in range(int(input())):
    main()