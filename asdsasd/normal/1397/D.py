import sys
input = sys.stdin.buffer.readline

def solve():
    n = int(input())
    alst = list(map(int, input().split()))
    if n == 1:
        print("T")
        return
    total = sum(alst)
    max_a = max(alst)
    if max_a * 2 > total:
        print("T")
    elif total % 2 == 0:
        print("HL")
    else:
        print("T")
t = int(input())
for _ in range(t):
    solve()