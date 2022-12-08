def main():
    n = input()
    ori_a = [int(x) for x in raw_input().split()]
    pos = {ori_a[i]: i for i in range(len(ori_a))}
    seg = [dict(left=None, right=None) for i in range(len(ori_a))]
    a = sorted(ori_a)
    seg_size = 0
    seg_num = 0
    fi_k = a[0]
    fi_seg_num = 0
    for n_items, item in enumerate(a, 1):
        i = pos[item]
        seg[i]["left"], seg[i]["right"] = i, i
        seg_num += 1
        size = seg[i]["right"] - seg[i]["left"] + 1
        if size > seg_size:
            seg_size = size
        li = pos[item] - 1
        if 0 <= li:
            if seg[li]["right"] == i - 1:
                seg[i]["left"] = seg[li]["left"]
                seg[li]["right"] = seg[i]["left"]
                seg_num -= 1
                size = seg[i]["right"] - seg[i]["left"] + 1
                if size > seg_size:
                    seg_size = size

        ri = pos[item] + 1
        if ri < n:
            if seg[ri]["left"] == i + 1:
                seg[i]["right"] = seg[ri]["right"]
                seg[ri]["left"] = seg[i]["left"]
                seg_num -= 1
                size = seg[i]["right"] - seg[i]["left"] + 1
                if size > seg_size:
                    seg_size = size
        if seg_size * seg_num == n_items and seg_num > fi_seg_num:
            fi_seg_num = seg_num
            fi_k = item + 1
    print(fi_k)
if __name__ == '__main__':
    main()