def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        alst = list(map(int, input().split()))
        ans = 0
        total = 0
        for a in alst:
            total -= a
            ans = max(ans, total)
        print(ans)
    
main()