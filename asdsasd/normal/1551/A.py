import sys
input = sys.stdin.readline
from bisect import bisect_left

def main():
    n = int(input())
    if n % 3 == 0:
        ans1 = n // 3
        ans2 = n // 3
    elif n % 3 == 1:
        ans1 = n // 3 + 1
        ans2 = n // 3
    else:
        ans1 = n // 3
        ans2 = n // 3 + 1
    print(ans1, ans2)
    
for _ in range(int(input())):
    main()