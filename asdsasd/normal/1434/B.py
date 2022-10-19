from bisect import bisect_right, bisect_left
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    pm = 0
    lst = []
    for _ in range(2 * n):
        s = input().strip().split()
        if s[0] == "+":
            pm += 1
            lst.append(-1)
        else:
            pm -= 1
            lst.append(int(s[1]))
            if pm < 0:
                print("NO")
                return
    ans = []
    que = []
    for i in lst[::-1]:
        if i == -1:
            ans.append(que.pop())
        else:
            if que and que[-1] < i:
                print("NO")
                return
            que.append(i)
    print("YES")
    print(*ans[::-1])
main()