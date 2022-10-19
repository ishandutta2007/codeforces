import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    if n == 1:
        print(S[0] * 2)
        return
    elif S[0] <= S[1]:
        print(S[0] * 2)
        return
    T = [S[0]]
    for i in range(1, n):
        if S[i] > S[i - 1]:
            break
        else:
            T.append(S[i])
    print("".join(T + T[::-1]))
        
    
for _ in range(int(input())):
    main()