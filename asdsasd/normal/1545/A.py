import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    dd_odd = defaultdict(int)
    dd_even = defaultdict(int)
    for i, a in enumerate(alst):
        if i % 2 == 0:
            dd_even[a] += 1
        else:
            dd_odd[a] += 1
    alst.sort()
    for i, a in enumerate(alst):
        if i % 2 == 0:
            if dd_even[a] == 0:
                print("NO")
                return
            dd_even[a] -= 1
        else:
            if dd_odd[a] == 0:
                print("NO")
                return
            dd_odd[a] -= 1
    print("YES")
    
for _ in range(int(input())):
    main()