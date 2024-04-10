import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    clst = list(map(int, input().split()))
    if clst[-1] not in blst:
        print("NO")
        return
    other = [[] for _ in range(n)]
    for i in range(n):
        if alst[i] != blst[i]:
            other[blst[i] - 1].append(i + 1)
        if blst[i] == clst[-1]:
            tmp = i + 1
    ans = []
    
    for c in clst[::-1]:
        c -= 1
        if other[c]:
            x = other[c].pop()
            ans.append(x)
            tmp = x
        else:
            ans.append(tmp)
    for row in other:
        if row:
            print("NO")
            return
    print("YES")    
    print(*ans[::-1])
    
    
for _ in range(int(input())):
    main()