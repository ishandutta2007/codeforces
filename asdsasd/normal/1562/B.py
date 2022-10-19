import sys
input = sys.stdin.readline

max_ = 10 ** 4
isprime = [True] * max_
for i in range(2, int(max_ ** 0.5 + 1)):
    if not isprime[i]:
        continue
    for j in range(i * i, max_, i):
        isprime[j] = False
        
composite = ["1"]
for i in range(2, max_):
    if not isprime[i]:
        composite.append(str(i))

def main():
    k = int(input())
    n = input()
    
    for S in composite:
        p = 0
        l = len(S)
        for i in n:
            if i == S[p]:
                p += 1
                if p == l:
                    print(l)
                    print(S)
                    return
    
    
    
for _ in range(int(input())):
    main()