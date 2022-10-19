def main():
    n = int(input())
    arr = list(map(int, input().split()))
    if n in {1, 2}:
        print(0)
        return
    x = arr[1] - arr[0]
    s = {x, x - 1, x - 2, x + 1, x + 2}
    for i in range(2, n):
        x = arr[i] - arr[i - 1]
        new_s = {x, x - 1, x - 2, x + 1, x + 2}
        s = s & new_s
        if not len(s):
            print(-1)
            return
    ans = float('inf')
    for step in s:
        for f in [arr[0], arr[0] + 1, arr[0] - 1]:
            new_arr = [f]
            cnt = 0 if f == arr[0] else 1
            for i in range(1, n):
                new_arr.append(new_arr[-1] + step)
                if abs(new_arr[-1] - arr[i]) > 1:
                    cnt = float('inf')
                    break
                if new_arr[-1] != arr[i]:
                    cnt += 1
            ans = min(ans, cnt)
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    main()