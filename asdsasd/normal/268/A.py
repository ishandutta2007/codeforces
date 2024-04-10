import sys
input = sys.stdin.readline

def main():
    from collections import defaultdict
    a_dd = defaultdict(int)
    b_dd = defaultdict(int)
    for _ in range(int(input())):
        a, b = map(int, input().split())
        a_dd[a] += 1
        b_dd[b] += 1
    ans = 0
    for key, value in a_dd.items():
        ans += value * b_dd[key]
    print(ans)
    
main()
"""
for _ in range(int(input())):
    main()
"""