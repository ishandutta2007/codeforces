import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    n = len(S)
    left = [True] * n
    for i in range(n - 1):
        left[i + 1] = left[i]
        if S[i] == "0":
            left[i + 1] = False
    
    right = [True] * n
    for i in range(n - 1, 0, -1):
        right[i - 1] = right[i]
        if S[i] == "1":
            right[i - 1] = False
    print(max(1, sum(l * r for l, r in zip(left, right))))
    
for _ in range(int(input())):
    main()