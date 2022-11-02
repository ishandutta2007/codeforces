n = int(input())
a = sorted(map(int, input().split()))
b = a[::2]
c = a[1::2][::-1]
print(' '.join(map(str, c + b)))