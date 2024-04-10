a = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
cnt = 0
s = input()
for i in a:
    cnt += s.count(i)
if cnt == 1:
    print('YES')
else:
    print('NO')