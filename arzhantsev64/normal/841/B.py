n = int(input())
a = list(map(int, input().split()))
ans = "Second"
for i in a:
	if i % 2 != 0:
		ans = "First"
		break
print(ans)