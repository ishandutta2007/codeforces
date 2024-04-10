import sys
input = sys.stdin.readline

def main():
    n = int(input())            
    slst = list(map(int, input().split()))
    ans = 0
    minus = [0] * (n + 1)
    for i, s in enumerate(slst):
        tmp = s - 1
        for j in range(2, s + 1):
            pos = i + j
            try:
                minus[pos] += 1
            except: break
        if tmp - minus[i] > 0:
            ans += tmp - minus[i]
        else:
            minus[i + 1] += minus[i] - tmp
        
    print(ans)
                
            
    
    
for _ in range(int(input())):
    main()