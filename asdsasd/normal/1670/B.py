import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    k, *T = input().strip().split()
    ng = [False] * 26
    for t in T:
        ng[ord(t) - 97] = True
    ind = 0
    ans = 0
    for i, s in enumerate(S):
        if ng[ord(s) - 97]:
            ans = max(ans, i - ind)
            ind = i
    
    
    print(ans)
    
for _ in range(int(input())):
    main()