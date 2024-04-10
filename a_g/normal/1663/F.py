s=input()
for w in "buffy","the","vampire","slayer":
    if len(w)==len(s):
        print(''.join(chr(97+(ord(s[i])+ord(w[i])-194)%26)for i in range(len(s))))
        exit(0)
print("none")