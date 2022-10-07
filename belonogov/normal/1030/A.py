# a = [0, 1]
# b = []

# print(a)
# print(b)
# b.append(78)
# b.append(78)
# print(b)
# print(a * 2 + b)
# s = 'dfsdfa   b c d e'
# print(s)
# print(s.split())
# t = input()
# print(t)
# print(type(t))
# print(t == '1 0 1 1 0')
# b = t.split()
# print(b)
i=0
n = int(input())
a = input().split()
flag=0
while n>i:
  if a[i] == '1':
    flag=1
  i=i+1

if flag==1:
  print('HARD')
else:
  print('EASY')


# # a = ((a // b) * b) + (a % b)
# n = int(input())
# a = [int(x) for x in input().split()]
# print(n)
# print(a)
# f=0

# a, b = [int(x) for x in input().split()]
# # a=int(input())
# # b=int(input())
# while a<=b:
#   a=a*3
#   b=b*2
#   f=f+1

# # i=1
# # while i<n:
# #   r=n-i
# #   if r % i == 0:
# #     qwe=qwe+1
# #     i=i+1
# #   else :   
# #     i=i+1

# print (f)