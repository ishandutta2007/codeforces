import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = [0, 0]
    for a in alst:
        cnt[a % 2] += 1
    if cnt[0] * cnt[1] == 0:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()