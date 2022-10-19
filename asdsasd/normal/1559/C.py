import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if alst[0] == 1:
        print(*([n + 1] + list(range(1, n + 1))))
    else:
        alst.append(1)
        for i in range(n):
            if alst[i] == 0 and alst[i + 1] == 1:
                print(*(list(range(1, i + 2)) + [n + 1] + list(range(i + 2, n + 1))))
                return
        
        
    
for _ in range(int(input())):
    main()