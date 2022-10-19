import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = [0] * 35
    bi = [1]
    for _ in range(34): bi.append(bi[-1] * 2)
    for a in A:
        cnt[a.bit_length() - 1] += 1
    for _ in range(q):
        b = int(input())
        c = 0
        for i in range(34, -1, -1):
            p = min(cnt[i], b // bi[i])
            c += p
            b -= bi[i] * p
        if b == 0:
            print(c)
        else:
            print(-1)
    
for _ in range(1):
    main()