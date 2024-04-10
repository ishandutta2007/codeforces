n = int(input())
arr = list(map(int, input().split()))
new_arr = []
s = set()
for i in range(n - 1, -1, -1):
    el = arr[i]
    if el not in s:
        s.add(el)
        new_arr.append(el)
print(len(new_arr))
print(*new_arr[::-1])