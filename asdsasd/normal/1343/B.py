import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if n % 4 != 0:
        print("NO")
        return
    print("YES")
    total = 0
    ans = []
    for i in range(2, n + 1, 2):
        ans.append(i)
        total += i
    for i in range(1, n - 1, 2):
        ans.append(i)
        total -= i
    ans.append(total)
    print(*ans)

"""
main()
"""
for _ in range(int(input())):
    main()