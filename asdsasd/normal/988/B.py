import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = [input().strip() for _ in range(n)]
    S.sort(key = lambda x:len(x))
    for i in range(1, n):
        if S[i - 1] not in S[i]:
            print("NO")
            return
    print("YES")
    for s in S:
        print(s)
    
for _ in range(1):
    main()