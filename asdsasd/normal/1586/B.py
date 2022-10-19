import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    tf = [True] * n
    for _ in range(m):
        a, b, c = map(int, input().split())
        tf[b - 1] = False
    for i, t in enumerate(tf):
        if t:
            ind = i
            break
    for i in range(n):
        if ind != i:
            print(i + 1, ind + 1)
    
for _ in range(int(input())):
    main()