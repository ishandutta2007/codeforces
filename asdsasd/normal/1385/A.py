import sys
input = sys.stdin.readline

def main():
    xyz = list(map(int, input().split()))
    max_ = max(xyz)
    if xyz.count(max_) == 1:
        print("NO")
        return
    print("YES")
    min_ = min(xyz)
    print(max_, min_, min_)
    
            
for _ in range(int(input())):
    main()