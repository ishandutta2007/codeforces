import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    clst = list(map(int, input().split()))
    ans = [alst[0]]
    for a, b in zip(alst[1:-1], blst[1:-1]):
        if ans[-1] != a:
            ans.append(a)
        else:
            ans.append(b)
    for abc in [alst[-1], blst[-1], clst[-1]]:
        if abc == ans[0]:
            continue
        elif abc == ans[-1]:
            continue
        else:
            ans.append(abc)
            break
    print(*ans)
    
for _ in range(int(input())):
    main()