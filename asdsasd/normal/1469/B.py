import sys
input = sys.stdin.readline

def main():
    n = int(input())
    R = list(map(int, input().split()))
    m = int(input())
    B = list(map(int, input().split()))
    mr = 0
    tot = 0
    for r in R:
        tot += r
        mr = max(mr, tot)
    mb = 0
    tot = 0
    for b in B:
        tot += b
        mb = max(mb, tot)
    print(mr + mb)
        
    
for _ in range(int(input())):
    main()