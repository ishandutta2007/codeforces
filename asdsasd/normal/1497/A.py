import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = []
    tmp = []
    alst.sort()
    bef = -1
    for a in alst:
        if bef == a:
            tmp.append(a)
        else:
            ans.append(a)
        bef = a
    print(*(ans + tmp))
    
    
for _ in range(int(input())):
    main()