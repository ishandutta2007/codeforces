
n = int(input())
a = list(map(int, input().split()))
b = [0] * n
for i in range(n):
    b[a[i] - 1] = i
for i in range(n):
    print(b[i] + 1, end = ' ');
print();

# print(b[0])
# print(b[1])
#
# print (2 ** 101)