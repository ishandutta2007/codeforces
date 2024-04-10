import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    A = list(map(int, input().split()))
    ans = 0
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    A.sort()
    for a in A:
        if cnt[a] > 0:
            if cnt.get(x * a, 0) > 0:
                cnt[a] -= 1
                cnt[x * a] -= 1
    print(sum(cnt.values()))
    
for _ in range(int(input())):
    main()