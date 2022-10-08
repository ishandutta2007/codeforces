
s = input()
a = [0] * 26;
for ch in s:
    a[ord(ch) - ord('a')] += 1

cnt = 0;
for x in a:
    if x > 0: 
        cnt += 1

#print(cnt)
print(["IGNORE HIM!", "CHAT WITH HER!"][1 - cnt % 2])