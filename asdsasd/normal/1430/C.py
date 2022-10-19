import sys
input = sys.stdin.readline

def main():
    n = int(input())
    stack = [i for i in range(1, n + 1)]
    ans = []
    while len(stack) > 1:
        ans.append((stack[-1], stack[-2]))
        app = (stack[-1] + stack[-2] + 1) // 2
        stack.pop()
        stack.pop()
        stack.append(app)
    print(stack[0])
    for row in ans:
        print(*row)
    
    
for _ in range(int(input())):
    main()