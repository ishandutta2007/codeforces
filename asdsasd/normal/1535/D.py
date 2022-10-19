import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    q = int(input())
    S = list("_" + S[::-1])
    l = 2 ** n
    data = [1] * (l * 2)
    N0 = l
    for i in range(N0 - 1, 0, -1):
        if S[i] == "0":
            data[i] = data[2 * i + 1]
        elif S[i] == "1":
            data[i] = data[2 * i]
        else:
            data[i] = data[2 * i] + data[2 * i + 1]
    for _ in range(q):
        p, c = input().strip().split()
        p = l - int(p)
        S[p] = c
        while p != 0:
            if S[p] == "0":
                data[p] = data[2 * p + 1]
            elif S[p] == "1":
                data[p] = data[2 * p]
            else:
                data[p] = data[2 * p] + data[2 * p + 1]
            p //= 2
        print(data[1])
    
    
    
for _ in range(1):
    main()