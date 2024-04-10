import sys
input = sys.stdin.readline

def main():
    S = input()
    T = input()
    ls = len(S)
    lt = len(T)
    S = S[::-1]
    T = T[::-1]
    for i in range(min(ls, lt)):
        if S[i] != T[i]:
            break
    else:
        i += 1
    print(ls + lt - i * 2)
    
for _ in range(1):
    main()