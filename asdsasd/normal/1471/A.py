import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    alst = list(map(int, input().split()))
    ans1 = (sum(alst) + x - 1) // x
    ans2 = 0
    for a in alst: ans2 += (a + x - 1) // x
    print(ans1, ans2)
    
    
for _ in range(int(input())):
    main()