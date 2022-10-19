import sys
input = sys.stdin.readline

def main():
    n = int(input())
    min_ = [10 ** 10, 0]
    max_ = [0, 0]
    inf = 1 << 60
    same = inf
    mi = {}
    for _ in range(n):
        l, r, c = map(int, input().split())
        mi[(l, r)] = min(mi.get((l, r), inf), c)
        if l < min_[0]:
            min_[0] = l
            min_[1] = c
        elif l == min_[0] and c < min_[1]:
            min_[1] = c
            
        if r > max_[0]:
            max_[0] = r
            max_[1] = c
        elif r == max_[0] and c < max_[1]:
            max_[1] = c
        
        ans = min(min_[1] + max_[1], mi.get((min_[0], max_[0]), inf))
        print(ans)
    
    
for _ in range(int(input())):
    main()