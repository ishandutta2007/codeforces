# # a = ((a // b) * b) + (a % b)

f=0

a, b = [int(x) for x in input().split()]
# a=int(input())
# b=int(input())
while a<=b:
  a=a*3
  b=b*2
  f=f+1

# i=1
# while i<n:
#   r=n-i
#   if r % i == 0:
#     qwe=qwe+1
#     i=i+1
#   else :   
#     i=i+1

print (f)