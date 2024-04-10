import sys
input = sys.stdin.readline
from bisect import bisect_left

lst = [0]
plus = 0
tot = 0
cnt = 0
n = 10 ** 9
while tot <= n:
    tot += plus
    cnt += 1
    if cnt % 3 == 0:
        pass
    else:
        plus += 2
    lst.append(tot)


def main():
    n = int(input())
    print(bisect_left(lst, n))


    
for _ in range(int(input())):
    main()