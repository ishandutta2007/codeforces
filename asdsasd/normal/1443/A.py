def main():
    n = int(input())
    ans = []
    for i in range(n):
        ans.append(4 * n - i * 2)
    print(*ans)

for _ in range(int(input())):
    main()