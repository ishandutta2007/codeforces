import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    for  a in A:
        cnt[a] = cnt.get(a, 0) + 1
    print(max(cnt.values()))
    
for _ in range(1):
    main()