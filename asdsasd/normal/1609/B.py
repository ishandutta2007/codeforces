import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    S = input()
    cnt = S.count("abc")
    S = list(S)
    for _ in range(q):
        i, c = input().split()
        i = int(i)
        i -= 1
        for j in range(i - 2, i + 1):
            if j < 0 or j >= n:
                continue
            if S[j:j+3] == ["a", "b", "c"]:
                cnt -= 1
        S[i] = c
        for j in range(i - 2, i + 1):
            if j < 0 or j >= n:
                continue
            if S[j:j+3] == ["a", "b", "c"]:
                cnt += 1
        print(cnt)
            
    
for _ in range(1):
    main()