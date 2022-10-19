import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    print((n - 1) // 2)
    ans = []
    r = n - 1
    l = 0
    alst.sort()
    if n == 1:
        print(alst[0])
        return
    while 1:
        ans.append(alst[r])
        r -= 1
        if r == l:
            break
        ans.append(alst[l])
        l += 1
        if r == l:
            break
    ans.append(alst[r])
    print(*ans)

    

main()