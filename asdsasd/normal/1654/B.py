import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    n = len(S)
    ind = n
    used = [False] * 26
    for i in range(n - 1, -1, -1):
        p = ord(S[i]) - 97
        if not used[p]:
            used[p] = True
            ind = i
    print(S[ind:])
    
for _ in range(int(input())):
    main()