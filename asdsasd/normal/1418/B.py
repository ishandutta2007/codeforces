import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    llst = list(map(int, input().split()))
    num = 10 ** 6
    ans = [num for _ in range(n)]
    lst = []
    for i, (a, l) in enumerate(zip(alst, llst)):
        if l:
            ans[i] = a
        else:
            lst.append(a)
    lst.sort(reverse = True)
    pos = 0
    for i in range(n):
        if ans[i] == num:
            ans[i] = lst[pos]
            pos += 1
    print(*ans)
    
for _ in range(int(input())):
    main()