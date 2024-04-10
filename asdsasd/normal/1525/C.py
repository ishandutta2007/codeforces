import sys
input = sys.stdin.readline
from math import gcd

def main():
    n, m = map(int, input().split())
    xlst = list(map(int, input().split()))
    Slst = list(input().strip().split())
    xs = [(x, s, i) for i, (x, s) in enumerate(zip(xlst, Slst))]
    xs.sort()
    odd = []
    even = []
    ans = [-1] * n
    for x, s, i in xs:
        if s == "R":
            if x % 2 == 0:
                even.append((i, x))
            else:
                odd.append((i, x))
        else:
            if x % 2 == 0:
                if even:
                    j, y = even.pop()
                    ans[i] = ans[j] = (x - y) // 2
                else:
                    even.append((i, -x))
            else:
                if odd:
                    j, y = odd.pop()
                    ans[i] = ans[j] = (x - y) // 2
                else:
                    odd.append((i, -x))
                    
    while len(even) >= 2:
        i, x = even.pop()
        j, y = even.pop()
        ans[i] = ans[j] = (x - y) // 2 + m - x
        
    while len(odd) >= 2:
        i, x = odd.pop()
        j, y = odd.pop()
        ans[i] = ans[j] = (x - y) // 2 + m - x
        
    print(*ans)
                
    
for _ in range(int(input())):
    main()