import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    klst = list(map(int, input().split()))
    clst = list(map(int, input().split()))
    klst.sort(reverse = True)
    ans = 0
    pos = 0
    clst += [10 ** 10]
    for k in klst:
        if k > pos:
            ans += clst[pos]
            pos += 1
        else:
            ans += clst[k - 1]
    print(ans)
    
for _ in range(int(input())):
    main()