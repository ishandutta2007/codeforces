def main():
    t = int(input())
    while t > 0:
        t -= 1
        n, k = [int(u) for u in input().split()]
        s = input()
        i = n - 1
        ans = 0
        first = 0
        for i in range(n):
            if s[i] == '*':
                first = i
                s = s[:i] + 'x' + s[i + 1:]
                ans = 1
                break
        while True:
            i = min(n - 1, first + k)
            found = False
            while i > first:
                if s[i] == '*':
                    first = i
                    found = True
                    break
                i -= 1
            if not found:
                break
            ans += 1
            s = s[:first] + 'x' + s[first + 1:]
        print(ans)

        

if __name__ == '__main__':
    main()