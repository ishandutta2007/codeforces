import sys
input = sys.stdin.readline

def main():
    k = int(input())
    dic = {}
    for i in range(1, k + 1):
        tot = 0
        n = int(input())
        A = list(map(int, input().split()))
        tot = sum(A)
        for j, a in enumerate(A, 1):
            tmp = tot - a
            if tmp not in dic:
                dic[tmp] = (i, j)
            elif dic[tmp][0] != i:
                print("YES")
                print(*dic[tmp])
                print(i, j)
                return
    print("NO")
            
    
for _ in range(1):
    main()