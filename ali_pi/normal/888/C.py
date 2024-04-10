s=raw_input()
print(min(max(map(len,s.split(i)))+1 for i in list(set(s))))