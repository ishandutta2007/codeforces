import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    odd = 0
    for a in alst:
        if a % 2 == 1: odd += 1
    if odd == n:
        print("Yes")
    else:
        print("No")
    
for _ in range(int(input())):
    main()