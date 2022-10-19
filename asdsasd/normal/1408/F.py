import sys
input = sys.stdin.readline

ans = []

def solve(n, start):
    if n == 1:
        return
    solve(n // 2, start)
    solve(n // 2, start + n // 2)
    for i in range(n // 2):
        ans.append(([start + i, start + i + n // 2]))

def main():
    n = int(input())
    s = format(n, "b")
    bin_s = [1]
    for i in range(len(s) - 1):
        bin_s.append(bin_s[-1] * 2)
    bin_s = bin_s[::-1]
    total = 1
    lst = [[] for _ in range(len(s))]
    for j, (ss, bb) in enumerate(zip(s, bin_s)):
        if ss == "1":
            for i in range(total, total + bb):
                lst[j].append(i)
            solve(bb, total)
            total += bb
    lst2 = lst[1:].copy()
    lst2 = lst2[::-1]
    zero_pos = 0
    lst0 = lst[0].copy()
    lst3 = []
    for lst in lst2:
        if lst3 == []:
            if lst == []:
                continue
            lst3 = lst.copy()
            tmp_lst = []
            for i in lst3:
                ans.append((i, lst0[zero_pos]))
                tmp_lst.append(lst0[zero_pos])
                zero_pos += 1
            for num in tmp_lst:
                lst3.append(num)
        elif lst == []:
            tmp_lst = []
            for i in lst3:
                ans.append((i, lst0[zero_pos]))
                tmp_lst.append(lst0[zero_pos])
                zero_pos += 1
            for num in tmp_lst:
                lst3.append(num)
        else:
            for i, j in zip(lst3, lst):
                ans.append((i, j))
            for j in lst:
                lst3.append(j)
            
    print(len(ans))
    for row in ans:
        print(*row)
        
main()