import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    inf = 10 ** 20
    ans = inf
    for i in range(1, n - 1):
        if alst[i - 1] > alst[i] ^ alst[i + 1]:
            print(1)
            return
    
    inf = 10 ** 30
    ans = inf
    for i in range(n):
        xor = 0
        for j in range(i - 1, -1, -1):
            xor ^= alst[j]
            if xor > alst[i]:
                ans = min(ans, i - j - 1)
                
    for i in range(n):
        xor = 0
        for j in range(i + 1, n):
            xor ^= alst[j]
            if xor < alst[i]:
                ans = min(ans, j - i - 1)
    
    for ir in range(1, n - 2):
        xor_i = alst[ir]
        for il in range(ir - 1, -1, -1):
            xor_i ^= alst[il]
            for jl in range(ir + 1, n - 1):
                xor_j = alst[jl]
                for jr in range(jl + 1, n):
                    xor_j ^= alst[jr]
                    if xor_i > xor_j:
                        
                        ans = min(ans, ir - il + jr - jl)
        
    if ans == inf:
        ans = -1
    print(ans)
    
for _ in range(1):
    main()