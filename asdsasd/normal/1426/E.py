import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    max_ = 0
    min_ = 0
    for i in range(3):
        max_ += min(alst[i], blst[(i + 1) % 3])
        min_ += max(0, alst[i] - blst[(i - 1) % 3] - blst[i])
    print(min_, max_)
    
main()