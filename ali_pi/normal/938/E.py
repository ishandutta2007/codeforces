def main():
    f= [1]
    for i in range(1,1000002):
        f.append((f[-1] * i)%1000000007)
    n = int(raw_input())
    a = sorted(int(x) for x in raw_input().split())
    sol = 0
    j = 0
    s = 1
    sq = 1
    for i in range(n - 1):
        sq = sq * (n - i) % 1000000007
        if a[i] != a[i + 1]:
            sol += a[i] * (i - j + 1) * f[n - j - 1] * s
            j = i + 1
            s = sq
    print(sol % 1000000007)
if __name__ == '__main__':
    main()