n = raw_input()
lst = [i for i in n]
if int(lst[0]) != 9 and int(lst[0]) >= 5:
	lst[0] = 9 - int(lst[0])
for j in range(1, len(n)):
	if int(lst[j]) >= 5: lst[j] = 9 - int(lst[j])
res = ""
for k in lst:
	res += str(k)
print int(res)