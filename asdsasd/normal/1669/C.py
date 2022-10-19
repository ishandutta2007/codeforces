import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = [[0, 0], [0, 0]]
    for i, a in enumerate(A):
        cnt[i%2][a%2] += 1
    
    for i in range(2):
        if cnt[i][0] > 0 and cnt[i][1] > 0:
            print("NO")
            return
    print("YES")
    
    
for _ in range(int(input())):
    main()