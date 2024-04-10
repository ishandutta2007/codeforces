import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    se = {alst[0]}
    for i in range(2, n):
        if alst[i] in se:
            print("YES")
            return
        se.add(alst[i - 1])
    print("NO")
    
for _ in range(int(input())):
    main()