import sys
input = sys.stdin.readline
from bisect import bisect_left

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    num = alst[k - 1]
    if num == 0:
        num = 1
    alst = alst[::-1]
    print(n - bisect_left(alst, num))

main()