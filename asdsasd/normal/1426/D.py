import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    dd = defaultdict(int)
    ans = 0
    total = 0
    dd[0] = 1
    for num in alst:
        total += num
        if dd[total] == 1:
            ans += 1
            dd = defaultdict(int)
            dd[0] = 1
            total = num
        dd[total] += 1
    print(ans)
    
main()