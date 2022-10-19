import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if max(alst) == min(alst):
        print(-1)
        return
    max_ = max(alst)
    for i, a in enumerate(alst):
        if a != max_:
            continue
        if i == 0:
            if alst[i] > alst[i + 1]:
                print(i + 1)
                return
        elif i == n - 1:
            if alst[i] > alst[i - 1]:
                print(i + 1)
                return
        else:
            if alst[i] > alst[i - 1] or alst[i] > alst[i + 1]:
                print(i + 1)
                return
        
    
for _ in range(int(input())):
    main()