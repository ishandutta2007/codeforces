import sys
cases = int(sys.stdin.readline())
input_arr = [int(x) for x in sys.stdin.readline().strip().split(" ")]

sort = sorted(input_arr)
sorted_dict = dict()
for i in range(0, len(sort)):
  sorted_dict[sort[i]] = i + 1

array = []
for x in input_arr:
  array.append(sorted_dict[x])

seen = set()

my_dict = dict()
for i in range(1, len(array) + 1):
  my_dict[i] = array[i - 1]
  
def find_permutation(seen, x):
  permutation = []
  while(x not in seen):
    permutation.append(x)
    seen.add(x)
    x = my_dict[x]
    
  return(str(len(permutation)) + " " + " ".join(str(x) for x in sorted(permutation)))

num_perms = 0
to_print = []
for x in array:
  if(x not in seen):
    num_perms += 1
    to_print.append(find_permutation(seen, x)) 
    seen.add(x)

print(num_perms)
print('\n'.join(to_print))