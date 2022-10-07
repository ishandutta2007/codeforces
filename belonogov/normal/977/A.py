n, k = [int(x) for x in input().split()]
# print(10 % 3)
# print(11 % 10)
# print(1123425 % 10)
# print(1123429 % 10)
# print(35345313432 % 10)
# print(type(5))
# print(type(5.2))
# print(6 / 3)
# print(6 // 3)
# print(5 / 3)
# print(5 // 3)
# 
# if 2 + 2 == 4:
  # print('2 + 2 == 4')
# else:
  # print('2 + 2 != 4')

i=0
while i < k:
  # print('k % 10' + '' * i)
  i=i+1  
  if n % 10 == 0:
    n=n//10
  else:
    n=n-1
print (n)
# k = 9999
# while 1 < k:
#   print ('')  
 
 

# print(2+2)
# a = 2
# b = 3
# print(a * b)