import sys
input = sys.stdin.readline

def ask(i):
    print(f"? {i + 1}", flush=True)
    return list(map(int, input().split()))

def main():
    n = int(input())
    ans = []
    dlst = ask(0)
    odd = []
    even = []
    for i, d in enumerate(dlst):
        if d % 2 == 0:
            even.append(i)
        else:
            odd.append(i)
    if len(even) <= len(odd):
        for i, d in enumerate(dlst):
            if d == 1:
                ans.append((1, i + 1))
    else:
        even = odd.copy()
    for i in even:
        if i == 0:
            continue
        dlst = ask(i)
        for j, d in enumerate(dlst):
            if d == 1:
                ans.append((i + 1, j + 1))
    
    print("!")
    for row in ans:
        print(*row)
for _ in range(1):
    main()