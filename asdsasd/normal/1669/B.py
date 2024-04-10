import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
        if cnt[a] >= 3:
            print(a)
            return
    print(-1)
    
for _ in range(int(input())):
    main()