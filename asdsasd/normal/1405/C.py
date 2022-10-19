def main():
    n, k = map(int, input().split())
    s = input()
    lst = ["2" for _ in range(k)]
    for i in range(n):
        if s[i] == "?":
            continue
        elif s[i] != lst[i % k] and lst[i % k] != "2":
            print("NO")
            return
        else:
            lst[i % k] = s[i]
    cnt0 = lst.count("0")
    cnt1 = lst.count("1")
    if cnt0 > k // 2 or cnt1 > k // 2:
        print("NO")
    else:
        print("YES")
        
t = int(input())
for _ in range(t):
    main()