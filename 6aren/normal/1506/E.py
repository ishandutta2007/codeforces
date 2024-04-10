def main():
    tt = int(input())
    while tt > 0:
        tt -= 1
        n = int(input())
        a = [int(u) for u in input().split()]
        ans1 = [0 for i in range(n)]
        prev = 0
        not_used = []
        for i in range(n):
            if a[i] != prev:
                ans1[i] = a[i]
                for j in range(prev + 1, a[i]):
                    not_used.append(j)
                prev = a[i]
        not_used.reverse()
        for i in range(n):
            if ans1[i] == 0:
                ans1[i] = not_used.pop()
        for i in range(n):
            print(ans1[i], end=' ')
        print()
        not_used = []
        ans2 = [0 for i in range(n)]
        prev = 0
        for i in range(n):
            if a[i] != prev:
                ans2[i] = a[i]
                for j in range(prev + 1, a[i]):
                    not_used.append(j)
                prev = a[i]
            else:
                ans2[i] = not_used.pop()
        for i in range(n):
            print(ans2[i], end=' ')
        print()


if __name__ == '__main__':
    main()