import sys
input = sys.stdin.readline

def main():
    d, k = map(int, input().split())
    n = d // k + 1
    i = d / (2 ** 0.5) // k
    dd = d ** 2
    kk = (i * k) ** 2
    cnt = int((dd - kk) ** 0.5) // k
    
    if (cnt - i) % 2 != 0: print("Ashish")
    else: print("Utkarsh")
    return
                

for _ in range(int(input())):
    main()