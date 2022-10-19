import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    input()
    alst.sort()
    blst.sort(reverse = True)
    for a, b in zip(alst, blst):
        if a + b > x:
            print("NO")
            return
    print("YES")

for _ in range(int(input())):
    main()