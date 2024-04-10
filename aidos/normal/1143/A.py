n = int(input())
a = ''.join(input().split())
print(min(a.rfind('0'),a.rfind('1')) + 1)