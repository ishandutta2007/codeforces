import sys
input = sys.stdin.readline

def main():
    l1, r1, l2, r2 = map(int, input().split())
    ans = l1 + l2
    if l1 <= l2 <= r1:
        ans = min(ans, l2)
    if l2 <= l1 <= r2:
        ans = min(ans, l1)
    print(ans)
    
    
for _ in range(int(input())):
    main()