n = gets.to_i
a = Array.new(n)
a = gets.split(" ").collect{|x| x.to_i}
numo=0
numa=0
for i in 0...n
  if (a[i]%2==0)
      numo+=1
  end
end
numa=n-numo
if (numo>numa)
    ans=numa
else
    ans=numo
end
numa-=ans
if (numa>0)
    ans+=numa/3
end
print ans