import sys
def send_request(x, y):
    print("{} {}".format(x, y))
    sys.stdout.flush()
    ans = input()
    if ans == 0:
        sys.exit(0)
    return ans
def main():
    n = int(raw_input().strip())
    x = 1
    y = 1
    send_request(x, y)
    prev_x_margin = 0
    prev_y_margin = 0
    x_margin = 1
    y_margin = 1
    while True:
        while True:
            ans = send_request(
                min(x + x_margin, n),
                min(y + y_margin, n)
            )
            if ans == 1:
                prev_x_margin = x_margin
                x_margin *= 2
            elif ans == 2:
                prev_y_margin = y_margin
                y_margin *= 2
            else:
                break
        if x_margin == 1 and y_margin == 1:
            while True:
                ans = send_request(
                    min(x + x_margin, n),
                    min(y + prev_y_margin, n)
                )
                if ans == 1:
                    prev_x_margin = x_margin
                    x_margin *= 2
                else:
                    break
            while True:
                ans = send_request(
                    min(x + prev_x_margin, n),
                    min(y + y_margin, n))
                if ans == 2:
                    prev_y_margin = y_margin
                    y_margin *= 2
                else:
                    break
        x = min(x + prev_x_margin, n)
        y = min(y + prev_y_margin, n)
        prev_x_margin = 0
        prev_y_margin = 0
        x_margin = max(1, x_margin // 2)
        y_margin = max(1, y_margin // 2)
if __name__ == "__main__":
    main()
    exit(0)